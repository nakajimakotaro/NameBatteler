//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_PLAYER_H
#define NAMEBATTLER_PLAYER_H


#include "../common/gameObject.h"
#include "../common/rect.h"
#include "../common/stateMachine.h"
#include "../common/collision.h"
#include <memory>
#include "../lib/json.hpp"

class Block;
class Enemy;
class Player final: public GameObject{
public:
    bool isReleaseKeyF = true;
    double speed = 1;
    std::string name;
    int range;
    double bottomX();
    double bottomY();
    std::shared_ptr<Block> rideCollisionBlock;
    std::shared_ptr<StateMachine<Player>> state;
public:
    Player(std::weak_ptr<Scene> scene, nlohmann::json json, std::string name);
    void start() override;
    void update() override;
    void draw() override;
    GameObject::Type getType() override;

    void shot();
};


#endif //NAMEBATTLER_PLAYER_H
