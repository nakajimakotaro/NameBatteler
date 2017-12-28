//
// Created by harus on 2017/12/28.
//

#include "player.h"
#include "../core/game.h"

Player::Player():
        rect(40, 40, 1, 1)
{

}

void Player::update() {

}

void Player::draw() {
    Game::get()->screen.writeChar('p', 30, 30);
}

GameObject::Type Player::getType() {
    return GameObject::Type::PLAYER;
}

