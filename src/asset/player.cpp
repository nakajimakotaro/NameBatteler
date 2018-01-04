//
// Created by harus on 2017/12/28.
//

#include "player.h"
#include "../core/game.h"
#include "playerRunState.h"
#include "playerJumpState.h"
#include "block.h"
#include "debugMessage.h"


std::shared_ptr<Player> Player::create() {
    auto ptr = std::shared_ptr<Player>(new Player());
    ptr->init();
    return ptr;
}

Player::Player():
        GameObject({}, 40 ,40)
{
}
void Player::init() {
    this->isOnBlock = false;
    this->state = StateMachine<Player>::create(shared_from_this(), PlayerRunState::name(), {PlayerRunState::mapPair(), PlayerJumpState::mapPair()});
    this->collider = std::make_shared<Collider>(shared_from_this(), 0, 1, 1, 1, [this](auto obj, auto overarea){
        this->isOnBlock = true;
    });
    Game::get()->scene->collision.addObjectRequire(this->collider);
}

void Player::update() {
    this->state->update();
}

void Player::draw() {
    Game::get()->screen.writeChar(this->isOnBlock ? 'b' : 'p', this->x(), this->y());
}

GameObject::Type Player::getType() {
    return GameObject::Type::PLAYER;
}
