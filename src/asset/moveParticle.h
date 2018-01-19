//
// Created by harus on 2018/01/10.
//

#ifndef NAMEBATTLER_MOVEPARTICLE_H
#define NAMEBATTLER_MOVEPARTICLE_H


#include "../common/gameObject.h"

class Player;
class MoveParticle: public GameObject{
public:
    MoveParticle(std::weak_ptr<Scene> scene);
    int lifeTime;
    std::weak_ptr<Player> player;
    void start() override;
    void update() override;
    void draw() override;
    GameObject::Type getType() override;
};


#endif //NAMEBATTLER_MOVEPARTICLE_H
