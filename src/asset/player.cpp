//
// Created by harus on 2017/12/28.
//

#include "player.h"
#include "../core/game.h"
#include "block.h"
#include "debugMessage.h"
#include "playerRunState.h"
#include "playerJumpState.h"
#include "playerFallState.h"
#include "enemy.h"
#include "camera.h"
#include "whipBullet.h"
#include "arrowBullet.h"
#include "../scene/inputManager.h"
#include "../scene/gameing/gameingInputManager.h"
#include "../scene/gameing/gameingScene.h"
Player::Player(std::weak_ptr<Scene> scene, nlohmann::json json, std::string name):
        GameObject(scene, json["x"].get<double>(), json["y"].get<double>()),
        name(name),
        range(3)
{
}
void Player::start() {
    this->state = StateMachine<Player>::create(std::dynamic_pointer_cast<Player>(shared_from_this()), PlayerRunState::name(), {
            PlayerRunState::mapPair(),
            PlayerJumpState::mapPair(),
            PlayerFallState::mapPair(),
    });

    //’n–Ê—p
    auto rideCollider = std::shared_ptr<Collider>(new Collider(this->scene, -3, 3, 6, 1, [this](auto obj, auto overarea){
        std::shared_ptr<GameObject> gameObject = (obj->getParent().lock());
            if(gameObject->getType() == GameObject::Type::BLOCK | gameObject->getType() == GameObject::Type::MOVEBLOCK) {
                this->rideCollisionBlock = std::dynamic_pointer_cast<Block>(gameObject);
            }
    }));
    this->addChild(rideCollider);
    this->scene.lock()->collision.addObjectRequire(rideCollider);

    //‘Ì
    auto bodyCollider = std::shared_ptr<Collider>(new Collider(this->scene, -6, -6, 11, 8, [this](std::shared_ptr<Collider> collider, Rect overarea){
        std::shared_ptr<GameObject> gameObject = (collider->getParent().lock());


        if(gameObject->getType() == GameObject::Type::BLOCK | gameObject->getType() == GameObject::Type::MOVEBLOCK) {
            double colliderCentorX = collider->x() + collider->w / 2;
            double colliderCentorY = collider->y() + collider->h / 2;
            double inDirectionX = colliderCentorX - overarea.centorX();
            double inDirectionY = colliderCentorY - overarea.centorY();
            if(abs(inDirectionX) > abs(inDirectionY)){
                if(inDirectionX < 0){
                    this->localX = collider->x() + collider->w + 6;
                }else{
                    this->localX = collider->x() - 6;
                }
            } else{
                if (inDirectionY < 0) {
                    this->localY = collider->y() + collider->h + 6;
                } else {
                    this->localY = collider->y() - 6;
                }
            }
        }
    }));
    this->addChild(bodyCollider);
    this->scene.lock()->collision.addObjectRequire(bodyCollider);
}

void Player::shot(){
    auto bullet = std::make_shared<ArrowBullet>(this->scene, this->x(), this->y(), this->getType(), this->direction == Direction::Right ? 0 : M_PI);
    this->scene.lock()->addObject(bullet);
}
void Player::update() {
    double prevX = this->x();
    if(this->isReleaseKeyF && this->scene.lock()->input.isPush(InputManager::LIST::KEY_F)){
        this->isReleaseKeyF = false;
        this->shot();
    }
    if(!this->scene.lock()->input.isPush(InputManager::LIST::KEY_F)){
        this->isReleaseKeyF = true;
    }
    this->state->update();
    this->rideCollisionBlock.reset();

    if(prevX > this->x()){
        this->moveDirection = Direction::Left;
        this->direction = Direction::Left;
    }else if(prevX < this->x()){
        this->moveDirection = Direction::Right;
        this->direction = Direction::Right;
    }else{
        this->moveDirection = Direction::Wait;
    }
}

void Player::draw() {
    this->state->draw();

    static int direNum = 0;
    switch (this->moveDirection){
        case Left:
            direNum = -1;
            break;
        case Right:
            direNum = 1;
            break;
    }

    const double num = 6;
    const double loopTime = 30;
    static int prevCountFrame = this->countFrame();
    for(int i = 0;i < num;i++){
        double percent;
        if(this->moveDirection == Direction::Wait){
            double garbage;
            percent = modf(prevCountFrame     / (double)loopTime + i / (double)num, &garbage);
        }else{
            double garbage;
            percent = modf(this->countFrame() / (double)loopTime + i / (double)num, &garbage);
            prevCountFrame = this->countFrame();
        }
        double x, y;
        x = std::cos(direNum * percent * M_PI * 2) * range * 2;
        y = std::sin(direNum * percent * M_PI * 2) * range    ;
        x += this->x();
        y += this->y();
        Game::get()->screen.writeChar(' ', x, y, Screen::ForColor::CYAN, Screen::BackColor::CYAN);
    }
    Game::get()->screen.writeChar('*', this->x(), this->y(), Screen::ForColor::MAGENTA);
}

GameObject::Type Player::getType() {
    return GameObject::Type::PLAYER;
}

double Player::bottomX() {
    return this->x();
}
double Player::bottomY() {
    return this->y() + this->range - 1;
}

