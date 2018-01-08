//
// Created by nakajimakotaro on 2018/01/02.
//

#ifndef NAMEBATTLER_BLOCK_H
#define NAMEBATTLER_BLOCK_H


#include "../common/gameObject.h"
#include "../common/rect.h"
#include "../common/collision.h"

class Block: public GameObject{
public:
    Block();
    void update();
    void start() override;
    void draw() override;
    Type getType() override {
        return GameObject::Type::BLOCK;
    }
};


#endif //NAMEBATTLER_BLOCK_H
