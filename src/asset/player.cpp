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
    auto bullet = std::make_shared<ArrowBullet>(this->scene, this->x(), this->y(), this->getType());
    this->scene.lock()->addObject(bullet);
}
void Player::update() {
    if(this->isReleaseKeyF && this->scene.lock()->input.isPush(InputManager::LIST::KEY_F)){
        this->isReleaseKeyF = false;
        this->shot();
    }
    if(!this->scene.lock()->input.isPush(InputManager::LIST::KEY_F)){
        this->isReleaseKeyF = true;
    }
    this->state->update();
    if(this->bottomY() > 50) {
        //this->scene.lock()->reset();
    }
    this->rideCollisionBlock.reset();
    this->scene.lock()->getObject<Camera>(GameObject::Type::CAMERA)->set();
}

void Player::draw() {
    this->state->draw();

    const double num = 6;
    const double loopTime = 30;
    for(int i = 0;i < num;i++){
        double x, y;
        double garbage;
        const double percent = modf(this->countFrame() / (double)loopTime + i / (double)num, &garbage);
        x = std::cos(-1 * percent * M_PI * 2) * range * 2;
        y = std::sin(-1 * percent * M_PI * 2) * range    ;
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

