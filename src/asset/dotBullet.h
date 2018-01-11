//
// Created by nakajimakotaro on 2018/01/11.
//

#ifndef NAMEBATTLER_DOTBULLET_H
#define NAMEBATTLER_DOTBULLET_H


#include "bullet.h"
#include "../core/screen.h"

class DotBullet: public Bullet{
private:
    std::shared_ptr<Collider> collider;
public:
    char text = ' ';
    Screen::ForColor forColor = Screen::ForColor::WHILE;
    Screen::BackColor backColor = Screen::BackColor::BLACK;
    int layer = 0;
public:
    DotBullet(double x, double y, GameObject::Type shotOwner);
    void start() override ;
    void update() override ;
    void draw() override ;
    void end() override ;

    Type getType(){
        return Type::DotBullet;
    }
};


#endif //NAMEBATTLER_DOTBULLET_H
