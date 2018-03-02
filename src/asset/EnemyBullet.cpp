//
// Created by harus on 2018/01/23.
//

#include "EnemyBullet.h"
#include "../scene/gameing/gameingScene.h"
#include "arrowBullet.h"

EnemyBullet::EnemyBullet(const std::weak_ptr<Scene> &scene, double x, double y, GameObject::Type shotOwner, double angle, double arc):
        Bullet(scene, x, y, shotOwner),
        angle(angle),
        arc(arc)
{
}

void EnemyBullet::start() {
}

void EnemyBullet::shot(){
    double num = 30;
    this->angle = this->countFrame() / 30.;
    for(int i = 0;i < num; i++){
        double x, y;
        double percent = i / (num - 1);
        double angle = this->angle - this->arc / 2 + percent * this->arc;
        auto bullet = std::shared_ptr<Bullet>(new ArrowBullet(this->scene, this->x(), this->y(), this->shotOwner, angle, Screen::BackColor::MAGENTA));
        this->scene.lock()->addObject(bullet);
    }
}
void EnemyBullet::update() {
    if(this->countFrame() % 10 == 0){
        this->shot();
    }
}

void EnemyBullet::draw() {
}

void EnemyBullet::end() {
}

GameObject::Type EnemyBullet::getType() {
    return Type::EnemyBullet;
}
