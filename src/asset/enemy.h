//
// Created by nakajimakotaro on 2018/01/05.
//

#ifndef NAMEBATTLER_ENEMY_H
#define NAMEBATTLER_ENEMY_H



#include "../common/gameObject.h"
class Enemy: public GameObject{
public:
    Enemy(std::weak_ptr<Scene> scene, double x, double y);
    void start() override;
    void update() override;
    void draw() override;
    Type getType() override {
        return GameObject::Type::ENEMY;
    }

    bool isCollision;
};



#endif //NAMEBATTLER_ENEMY_H
