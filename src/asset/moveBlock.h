//
// Created by harus on 2018/01/22.
//

#ifndef NAMEBATTLER_MOVEBLOCK_H
#define NAMEBATTLER_MOVEBLOCK_H


#include "../common/gameObject.h"
#include "../lib/json.hpp"
#include "block.h"

template <typename T> class StateMachine;
class MoveBlock: public Block {
public:
    double startX;
    double startY;
    double goalX;
    double goalY;
    std::shared_ptr<StateMachine<MoveBlock>> state;
    double prevMoveX;
    double prevMoveY;
public:
    MoveBlock(const std::weak_ptr<Scene> &scene, double startX, double startY, double goalX, double goalY, double w, double h);
    MoveBlock(std::weak_ptr<Scene> scene, nlohmann::json json);
    void start() override;
    void update() override;
    void draw() override;
    void end() override;
    Type getType() override {
        return GameObject::Type::MOVEBLOCK;
    }
};


#endif //NAMEBATTLER_MOVEBLOCK_H
