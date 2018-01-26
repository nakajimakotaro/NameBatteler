//
// Created by nakajimakotaro on 2018/01/02.
//

#ifndef NAMEBATTLER_BLOCK_H
#define NAMEBATTLER_BLOCK_H


#include "../common/gameObject.h"
#include "../common/rect.h"
#include "../common/collision.h"
#include "../lib/json.hpp"

class Block: public GameObject{
private:
    std::shared_ptr<Collider> collider;
public:
    double w, h;
    Block(std::weak_ptr<Scene> scene, double localX, double localY, double w, double h);
    Block(std::weak_ptr<Scene> scene, nlohmann::json json);
    virtual void update() override;
    virtual void start() override;
    virtual void draw() override;
    virtual void end() override;
    virtual Type getType() override {
        return GameObject::Type::BLOCK;
    }
};


#endif //NAMEBATTLER_BLOCK_H
