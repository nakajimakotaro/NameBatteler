//
// Created by nakajimakotaro on 2018/01/05.
//

#include "enemy.h"
#include "../core/game.h"

Enemy::Enemy(double x, double y):
        GameObject(x, y)
{
    isCollision = false;
}
void Enemy::start(){
    isCollision = false;
    std::shared_ptr<Collider> collider = std::make_shared<Collider>(0, 0, 1, 1, [this](auto obj, auto overarea){ });
    Game::get()->scene->collision.addObjectRequire(collider);
}
void Enemy::update() {
}
void Enemy::draw() {
    Game::get()->screen.writeChar('*', this->x(), this->y());
}

