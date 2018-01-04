//
// Created by nakajimakotaro on 2018/01/02.
//

#ifndef NAMEBATTLER_CAMERA_H
#define NAMEBATTLER_CAMERA_H


#include "gameObject.h"
#include "player.h"

class Camera : public GameObject{
public:
    Camera();
    std::weak_ptr<Player> player;

    void start();
    void update();
    Type getType() {
        return GameObject::Type::CAMERA;
    }
};


#endif //NAMEBATTLER_CAMERA_H
