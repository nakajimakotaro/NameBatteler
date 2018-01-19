//
// Created by harus on 2018/01/10.
//

#include "moveParticle.h"
#include "../core/game.h"
#include "player.h"
#include "../scene/gameing/gameingScene.h"

MoveParticle::MoveParticle(std::weak_ptr<Scene> scene):
        GameObject(scene, 0, 0)
{
}


GameObject::Type MoveParticle::getType() {
    return GameObject::Type::MoveParticle;
}

void MoveParticle::start() {
    this->player = this->scene.lock()->getObject<Player>(GameObject::Type::PLAYER);
}

void MoveParticle::update() {
}

void MoveParticle::draw() {
}

