//
// Created by nakajimakotaro on 2018/01/04.
//

#ifndef NAMEBATTLER_COLLIDER_H
#define NAMEBATTLER_COLLIDER_H


#include "../asset/gameObject.h"
#include "rect.h"

class Collider final: public GameObject{
public:
    Collider(double localX, double localY, double w, double h, std::function<void(std::shared_ptr<Collider>, Rect)> collision);
    double w;
    double h;
    std::function<void(std::shared_ptr<Collider>, Rect)> collision;
    GameObject::Type getType() override {
        return GameObject::Type::COLLIDER;
    }

};


#endif //NAMEBATTLER_COLLIDER_H
