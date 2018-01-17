//
// Created by harus on 2017/12/29.
//

#ifndef NAMEBATTLER_GAMEINGCONTROLLER_H
#define NAMEBATTLER_GAMEINGCONTROLLER_H


#include <c++/memory>
#include "../inputManager.h"
#include "gameingScene.h"

class GameingInputManager final: public InputManager{
private:
    std::weak_ptr<GameingScene> scene;
public:
    GameingInputManager(std::weak_ptr<GameingScene> scene);
    void update() override;
};


#endif //NAMEBATTLER_GAMEINGCONTROLLER_H
