//
// Created by nakajimakotaro on 2018/01/05.
//

#include "enemy.h"
#include "../core/game.h"
#include "../scene/gameing/gameingScene.h"
#include "bullet.h"
#include "EnemyBullet.h"
#include "arrowBullet.h"

Enemy::Enemy(std::weak_ptr<Scene> scene, double x, double y):
        GameObject(scene, x, y),
        hp(10)
{
    isCollision = false;
}
Enemy::Enemy(std::weak_ptr<Scene> scene, nlohmann::json json):
        Enemy(scene, json["x"].get<double>(), json["y"].get<double>())
{
}
void Enemy::start(){
    isCollision = false;
    std::shared_ptr<Collider> collider = std::make_shared<Collider>(this->scene, -3, -1, 4, 6, [this](auto obj, auto overarea){
        std::shared_ptr<GameObject> gameObject = (obj->getParent().lock());
        if(!gameObject){
            return;
        }
        if(gameObject->getType() == Type::ArrowBullet){
            if(std::dynamic_pointer_cast<ArrowBullet>(gameObject)->shotOwner == Type::PLAYER){
                this->hp--;
            }
        }
    });
    this->addChild(collider);
    this->scene.lock()->collision.addObjectRequire(collider);

    this->bullet = std::shared_ptr<Bullet>(new EnemyBullet(this->scene, this->x(), this->y(), Type::ENEMY, 0, M_PI / 4));
    this->scene.lock()->addObject(bullet);
}
void Enemy::update() {
    if(this->hp <= 0){
        this->scene.lock()->removeObject(shared_from_this());
    }
}
void Enemy::draw() {
    Game::get()->screen.writeString(R"(\\\\\\)", this->x(), this->y() - 1);
    Game::get()->screen.writeString(R"(\\**\\)", this->x(), this->y());
    Game::get()->screen.writeString(R"(\\\\\\)", this->x(), this->y() + 1);
    Game::get()->screen.writeString(R"(  || /)", this->x(), this->y() + 2);
    Game::get()->screen.writeString(R"(  ||/ )", this->x(), this->y() + 3);
    Game::get()->screen.writeString(R"(  ||  )", this->x(), this->y() + 4);
}

void Enemy::end() {
    this->scene.lock()->removeObject(this->bullet);
}

