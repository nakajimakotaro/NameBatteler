//
// Created by nakajimakotaro on 2018/01/02.
//

#ifndef NAMEBATTLER_BLOCK_H
#define NAMEBATTLER_BLOCK_H


#include "gameObject.h"
#include "../common/rect.h"
#include "../common/collision.h"

class Block: public GameObject, public std::enable_shared_from_this<Block>{
public:
    Block();
    void update();
    void start() override;
    void draw() override;
    Type getType() override {
        return GameObject::Type::BLOCK;
    }

    bool isCollision;
};


#endif //NAMEBATTLER_BLOCK_H
