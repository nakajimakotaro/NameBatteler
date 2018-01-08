//
// Created by nakajimakotaro on 2018/01/03.
//

#ifndef NAMEBATTLER_COLLISION_H
#define NAMEBATTLER_COLLISION_H


#include <memory>
#include <vector>
#include "rect.h"
#include "collider.h"
class Collision {
private:
    std::vector<std::shared_ptr<Collider>> collisionList;
    std::vector<std::shared_ptr<Collider>> addQueue;
    std::vector<std::shared_ptr<Collider>> removeQueue;
public:
    Collision() = default;
    void addObjectRequire(std::shared_ptr<Collider> obj);
    void removeObjectRequire(std::shared_ptr<Collider> obj);
    void tick();
private:
    void ququeExe();
};


#endif //NAMEBATTLER_COLLISION_H
