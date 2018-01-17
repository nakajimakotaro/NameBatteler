//
// Created by nakajimakotaro on 2018/01/05.
//

#include "enemy.h"
#include "../core/game.h"
#include "../scene/gameing/gameingScene.h"

Enemy::Enemy(std::weak_ptr<GameingScene> scene, double x, double y):
        GameObject(scene, x, y)
{
    isCollision = false;
}
void Enemy::start(){
    isCollision = false;
    std::shared_ptr<Collider> collider = std::make_shared<Collider>(this->scene, 0, 0, 1, 1, [this](auto obj, auto overarea){ });
    this->scene.lock()->collision.addObjectRequire(collider);
}
void Enemy::update() {
}
void Enemy::draw() {
    Game::get()->screen.writeChar('*', this->x(), this->y());
}

