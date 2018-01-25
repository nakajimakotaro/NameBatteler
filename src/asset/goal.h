//
// Created by nakajimakotaro on 2018/01/25.
//

#ifndef NAMEBATTLER_GOAL_H
#define NAMEBATTLER_GOAL_H


#include "../common/gameObject.h"
#include "../lib/json.hpp"

class Goal: public GameObject {
public:
    Goal(std::weak_ptr<Scene> scene, double localX, double localY);
    Goal(std::weak_ptr<Scene> scene, nlohmann::json json);
    void start() override ;
    void update() override ;
    void draw() override ;
    Type getType(){
        return Type::Goal;
    }
};


#endif //NAMEBATTLER_GOAL_H
