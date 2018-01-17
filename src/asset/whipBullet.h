//
// Created by nakajimakotaro on 2018/01/11.
//

#ifndef NAMEBATTLER_WHIPBULLET_H
#define NAMEBATTLER_WHIPBULLET_H


#include "bullet.h"
#include "dotBullet.h"

class WhipBullet: public Bullet{
private:
    std::shared_ptr<Collider> collider;
    std::vector<std::shared_ptr<DotBullet>> bulletList;
public:
    WhipBullet(std::weak_ptr<GameingScene> scene, double x, double y, GameObject::Type shotOwner);
    void start() override ;
    void update() override ;
    void draw() override ;
    void end() override ;
    Type getType(){
        Type::WhipBullet;
    }

};


#endif //NAMEBATTLER_WHIPBULLET_H
