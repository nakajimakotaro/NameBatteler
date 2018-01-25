//
// Created by harus on 2018/01/23.
//

#ifndef NAMEBATTLER_ENEMYBULLET_H
#define NAMEBATTLER_ENEMYBULLET_H


#include "bullet.h"

class EnemyBullet: public Bullet{
public:
    double angle;
    double arc;
    EnemyBullet(const std::weak_ptr<Scene> &scene, double x, double y, Type shotOwner, double angle, double arc);
    void start() override ;
    void update() override ;
    void draw() override ;
    void end() override ;

    void shot();

    GameObject::Type getType() override;
};


#endif //NAMEBATTLER_ENEMYBULLET_H
