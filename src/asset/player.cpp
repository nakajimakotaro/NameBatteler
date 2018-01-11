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


std::shared_ptr<Player> Player::create() {
    auto ptr = std::shared_ptr<Player>(
            new Player()
    );
    ptr->init();
    return ptr;
}

Player::Player():
        GameObject(40 ,37),
        range(3)
{
}
void Player::init() {
    this->state = StateMachine<Player>::create(std::dynamic_pointer_cast<Player>(shared_from_this()), PlayerRunState::name(), {
            PlayerRunState::mapPair(),
            PlayerJumpState::mapPair(),
            PlayerFallState::mapPair(),
    });
    auto collisionFunc = [this](auto obj, auto overarea){
        std::shared_ptr<GameObject> gameObject = (obj->getParent().lock());
        switch (gameObject->getType()){
            case Type::PLAYER:break;
            case Type::CAMERA:break;
            case Type::BLOCK:
                this->collisionBlock = std::dynamic_pointer_cast<Block>(gameObject);
                break;
            case Type::MESSAGE_AREA:break;
            case Type::DEBUG_MESSAGE:break;
            case Type::COLLIDER:break;
            case Type::ENEMY:
                this->collisionEnemy = std::dynamic_pointer_cast<Enemy>(gameObject);
                break;
            case Type::Layer:break;
            case Type::Particle:break;
            case Type::MoveParticle:break;
        }
    };
    auto collider = std::shared_ptr<Collider>(new Collider(-3, 3, 6, 1, collisionFunc));
    this->addChild(collider);
    Game::get()->scene->collision.addObjectRequire(collider);
}

void Player::shot(){
    auto bullet = std::shared_ptr<WhipBullet>(new WhipBullet(0, 0, this->getType()));
    Game::get()->scene->addObject(bullet);
    this->addChild(bullet);
}
void Player::update() {
    if(this->isReleaseKeyF && Game::get()->scene->inputManager.isPush(InputManager::LIST::KEY_F)){
        this->isReleaseKeyF = false;
        this->shot();
    }
    if(!Game::get()->scene->inputManager.isPush(InputManager::LIST::KEY_F)){
        this->isReleaseKeyF = true;
    }
    this->state->update();
    this->collisionBlock.reset();
    Game::get()->scene->getObject<Camera>(GameObject::Type::CAMERA)->set();
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
