//
// Created by nakajimakotaro on 2018/01/05.
//

#ifndef NAMEBATTLER_ENEMY_H
#define NAMEBATTLER_ENEMY_H



#include "gameObject.h"
class Enemy: public GameObject{
public:
    Enemy();
    void start() override;
    void update() override;
    void draw() override;
    Type getType() override {
        return GameObject::Type::ENEMY;
    }

    bool isCollision;
};



#endif //NAMEBATTLER_ENEMY_H
