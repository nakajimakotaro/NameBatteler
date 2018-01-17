//
// Created by nakajimakotaro on 2018/01/02.
//

#ifndef NAMEBATTLER_CAMERA_H
#define NAMEBATTLER_CAMERA_H


#include "../common/gameObject.h"
#include "player.h"

class Camera : public GameObject{
public:
    Camera(std::weak_ptr<GameingScene> scene);
    std::weak_ptr<Player> player;

    void start();
    Type getType() {
        return GameObject::Type::CAMERA;
    }
    void set();
};


#endif //NAMEBATTLER_CAMERA_H
