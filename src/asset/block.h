//
// Created by nakajimakotaro on 2018/01/02.
//

#ifndef NAMEBATTLER_BLOCK_H
#define NAMEBATTLER_BLOCK_H


#include "../common/gameObject.h"
#include "../common/rect.h"
#include "../common/collision.h"

class Block: public GameObject{
private:
    std::shared_ptr<Collider> collider;
    double w, h;
public:
    Block(std::weak_ptr<GameingScene> scene, double x, double y, double w, double h);
    void update() override;
    void start() override;
    void draw() override;
    void end() override;
    Type getType() override {
        return GameObject::Type::BLOCK;
    }
};


#endif //NAMEBATTLER_BLOCK_H
