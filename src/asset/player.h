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
#include "../common/json.h"

class Block;
class Enemy;

class Player final: public GameObject{
public:
    enum Direction{
        Left,
        Right,
        Wait
    };
    bool isReleaseKeyF = true;
    Direction moveDirection = Direction::Wait;
    Direction direction = Direction::Left;
    double speed = 2;
    std::string name;
    int range;
    int hp;
    int prevDamage = 0;
    double bottomX();
    double bottomY();
    std::shared_ptr<Block> rideCollisionBlock;
    std::shared_ptr<StateMachine<Player>> state;
public:
    Player(std::weak_ptr<Scene> scene, MyJson::JsonInterFace json, std::string name);
    void start() override;
    void update() override;
    void draw() override;
    void postUpdate() override;
    GameObject::Type getType() override;

    void shot();
};


#endif //NAMEBATTLER_PLAYER_H
