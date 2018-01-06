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


std::shared_ptr<Player> Player::create() {
    auto ptr = std::shared_ptr<Player>(new Player());
    ptr->init();
    return ptr;
}

Player::Player():
        GameObject({}, 40 ,46)
{
}
void Player::init() {
    this->state = StateMachine<Player>::create(shared_from_this(), PlayerRunState::name(), {
            PlayerRunState::mapPair(),
            PlayerJumpState::mapPair(),
            PlayerFallState::mapPair(),
    });
    this->collider = std::make_shared<Collider>(shared_from_this(), 0, 1, 1, 1, [this](auto obj, auto overarea){
        std::shared_ptr<GameObject> gameObject = (obj->parent.lock());
        switch (gameObject->getType()){
            case Type::PLAYER:break;
            case Type::CAMERA:break;
            case Type::BLOCK:
                this->collisionBlock = std::dynamic_pointer_cast<Block>(gameObject);
                break;
            case Type::MESSAGE_AREA:break;
            case Type::DEBUG_MESSAGE:break;
            case Type::COLLIDER:break;
            case Type::ENEMY:break;
                this->collisionEnemy = std::dynamic_pointer_cast<Enemy>(gameObject);
        }
    });
    Game::get()->scene->collision.addObjectRequire(this->collider);
}

void Player::update() {
    this->state->update();
    this->collisionBlock.reset();
}

void Player::draw() {
    Game::get()->screen.writeChar('p', this->x(), this->y());
}

GameObject::Type Player::getType() {
    return GameObject::Type::PLAYER;
}
