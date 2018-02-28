//
// Created by nakajimakotaro on 2018/01/05.
//

#ifndef NAMEBATTLER_ENEMY_H
#define NAMEBATTLER_ENEMY_H


#include "../common/gameObject.h"
#include "../common/json.h"

class Bullet;
class Enemy: public GameObject{
private:
    std::shared_ptr<Bullet> bullet;
    int hp;
public:
    Enemy(std::weak_ptr<Scene> scene, double x, double y);
    Enemy(std::weak_ptr<Scene> scene, std::shared_ptr<MyJson::JsonInterFace> json);
    void start() override;
    void update() override;
    void draw() override;
    void end() override;
    Type getType() override {
        return GameObject::Type::ENEMY;
    }

    bool isCollision;
};



#endif //NAMEBATTLER_ENEMY_H
