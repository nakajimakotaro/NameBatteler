//
// Created by nakajimakotaro on 2018/01/05.
//

#ifndef NAMEBATTLER_ENEMY_H
#define NAMEBATTLER_ENEMY_H


#include "../common/gameObject.h"
#include "../lib/json.hpp"
class Enemy: public GameObject{
public:
    Enemy(std::weak_ptr<Scene> scene, double x, double y);
    Enemy(std::weak_ptr<Scene> scene, nlohmann::json json);
    void start() override;
    void update() override;
    void draw() override;
    Type getType() override {
        return GameObject::Type::ENEMY;
    }

    bool isCollision;
};



#endif //NAMEBATTLER_ENEMY_H
