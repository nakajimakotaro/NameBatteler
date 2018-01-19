//
// Created by harus on 2018/01/12.
//

#ifndef NAMEBATTLER_ARROWBULLET_H
#define NAMEBATTLER_ARROWBULLET_H


#include "bullet.h"

class ArrowBullet: public Bullet {
public:
    ArrowBullet(std::weak_ptr<Scene> scene, double x, double y, Type ownerType);
    void start() override ;
    void update() override ;
    void draw() override ;
    void end() override ;
    Type getType() override {
        return Type::ArrowBullet;
    }
};


#endif //NAMEBATTLER_ARROWBULLET_H
