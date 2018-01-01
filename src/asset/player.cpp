//
// Created by harus on 2017/12/28.
//

#include "player.h"
#include "../core/game.h"
#include "playerRunState.h"
#include "playerJumpState.h"


std::shared_ptr<Player> Player::create() {
    auto ptr = std::shared_ptr<Player>(new Player());
    ptr->init();
    return ptr;
}

Player::Player():
        rect(40, 40, 1, 1)
{
}
void Player::init() {
    this->state = StateMachine<Player>::create(shared_from_this(), PlayerRunState::name(), {PlayerRunState::mapPair(), PlayerJumpState::mapPair()});
}

void Player::update() {
    this->state->update();
}

void Player::draw() {
    Game::get()->screen.writeChar('p', this->rect.x, this->rect.y);
}

GameObject::Type Player::getType() {
    return GameObject::Type::PLAYER;
}

void Player::jump() {
}


