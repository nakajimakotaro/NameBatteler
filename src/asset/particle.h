//
// Created by harus on 2018/01/08.
//

#ifndef NAMEBATTLER_PARTICLE_H
#define NAMEBATTLER_PARTICLE_H


#include "../common/gameObject.h"

class Particle: public GameObject{
public:
    int countFrame;
public:
    Particle(std::weak_ptr<Scene> scene, double x, double y);
    void update() override;
    void draw() override;
    Type getType() override {
       GameObject::Type::Particle;
    }
};


#endif //NAMEBATTLER_PARTICLE_H
