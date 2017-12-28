//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_PLAYER_H
#define NAMEBATTLER_PLAYER_H


#include "gameObject.h"
#include "rect.h"

class Player final: public GameObject{
public:
    Rect rect;
    Player();
public:
    void update() override;
    void draw() override;
    GameObject::Type getType() override;
};


#endif //NAMEBATTLER_PLAYER_H
