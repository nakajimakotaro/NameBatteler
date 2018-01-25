//
// Created by nakajimakotaro on 2018/01/05.
//

#include "enemy.h"
#include "../core/game.h"
#include "../scene/gameing/gameingScene.h"
#include "bullet.h"
#include "EnemyBullet.h"

Enemy::Enemy(std::weak_ptr<Scene> scene, double x, double y):
        GameObject(scene, x, y)
{
    isCollision = false;
}
Enemy::Enemy(std::weak_ptr<Scene> scene, nlohmann::json json):
        GameObject(scene, json["x"].get<double>(), json["y"].get<double>())
{
}
void Enemy::start(){
    isCollision = false;
    std::shared_ptr<Collider> collider = std::make_shared<Collider>(this->scene, 0, 0, 1, 1, [this](auto obj, auto overarea){ });
    this->scene.lock()->collision.addObjectRequire(collider);

    this->bullet = std::shared_ptr<Bullet>(new EnemyBullet(this->scene, this->x(), this->y(), Type::ENEMY, 0, M_PI / 4));
    this->scene.lock()->addObject(bullet);
}
void Enemy::update() {
}
void Enemy::draw() {
    Game::get()->screen.writeString(R"(\\\\\\)", this->x(), this->y() - 1);
    Game::get()->screen.writeString(R"(\\**\\)", this->x(), this->y());
    Game::get()->screen.writeString(R"(\\\\\\)", this->x(), this->y() + 1);
}

void Enemy::end() {
    this->scene.lock()->removeObject(this->bullet);
}

