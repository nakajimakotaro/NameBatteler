//
// Created by harus on 2017/12/29.
//

#ifndef NAMEBATTLER_GAMEINGCONTROLLER_H
#define NAMEBATTLER_GAMEINGCONTROLLER_H


#include "../inputManager.h"

class GameingInputManager final: public InputManager{
public:
    void update() override;
};


#endif //NAMEBATTLER_GAMEINGCONTROLLER_H
