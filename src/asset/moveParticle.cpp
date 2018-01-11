//
// Created by harus on 2018/01/10.
//

#include "moveParticle.h"
#include "../core/game.h"
#include "player.h"

MoveParticle::MoveParticle():
        GameObject(0, 0)
{
}


GameObject::Type MoveParticle::getType() {
    return GameObject::Type::MoveParticle;
}

void MoveParticle::start() {
    this->player = Game::get()->scene->getObject<Player>(GameObject::Type::PLAYER);
}

void MoveParticle::update() {
}

void MoveParticle::draw() {
}

