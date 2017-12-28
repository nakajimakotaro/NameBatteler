//
// Created by harus on 2017/12/28.
//

#include "player.h"

Player::Player():
        rect(40, 40, 1, 1)
{

}

void Player::update() {

}

void Player::draw() {
}

GameObject::Type Player::getType() {
    return GameObject::Type::PLAYER;
}

