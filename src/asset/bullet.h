//
// Created by nakajimakotaro on 2018/01/11.
//

#ifndef NAMEBATTLER_BULLET_H
#define NAMEBATTLER_BULLET_H


#include "../common/gameObject.h"
#include "../common/collider.h"

class Bullet: public GameObject {
public:
    GameObject::Type shotOwner;
public:
    Bullet(std::weak_ptr<GameingScene> scene, double x, double y, GameObject::Type shotOwner):
            GameObject(scene, x, y),
            shotOwner(shotOwner){ }
};


#endif //NAMEBATTLER_BULLET_H
