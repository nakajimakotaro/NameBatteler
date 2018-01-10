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
class Block;
class Enemy;
class Player final: public GameObject{
public:
    static std::shared_ptr<Player> create();
private:
    Player();
    void init();
public:
    double speed = 1;
    double bottomX();
    double bottomY();
    int range;
    std::shared_ptr<Block> collisionBlock;
    std::shared_ptr<Enemy> collisionEnemy;
    std::shared_ptr<StateMachine<Player>> state;
    void update() override;
    void draw() override;
    std::shared_ptr<GameObject> s_this();
    GameObject::Type getType() override;
};


#endif //NAMEBATTLER_PLAYER_H
