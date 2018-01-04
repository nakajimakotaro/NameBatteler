//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_PLAYER_H
#define NAMEBATTLER_PLAYER_H


#include "gameObject.h"
#include "../common/rect.h"
#include "../common/stateMachine.h"
#include "../common/collision.h"
#include <memory>

class Block;
class Player final: public GameObject, public std::enable_shared_from_this<Player>{
public:
    static std::shared_ptr<Player> create();
private:
    Player();
    void init();

private:
    std::shared_ptr<Collider> collider;
public:
    int speed = 1;
    std::shared_ptr<Block> collisionBlock;
    std::shared_ptr<StateMachine<Player>> state;
    void update() override;
    void draw() override;
    GameObject::Type getType() override;
};


#endif //NAMEBATTLER_PLAYER_H
