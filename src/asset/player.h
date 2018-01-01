//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_PLAYER_H
#define NAMEBATTLER_PLAYER_H


#include "gameObject.h"
#include "../common/rect.h"
#include "../common/stateMachine.h"
#include <memory>

class Player final: public GameObject, public std::enable_shared_from_this<Player>{
public:
    static std::shared_ptr<Player> create();
private:
    Player();
    void init();
public:
    Rect rect;
public:
    std::shared_ptr<StateMachine<Player>> state;
    void update() override;
    void draw() override;
    GameObject::Type getType() override;
    void jump();
};


#endif //NAMEBATTLER_PLAYER_H
