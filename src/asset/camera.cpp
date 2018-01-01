//
// Created by nakajimakotaro on 2018/01/02.
//

#include "camera.h"
#include "../core/screen.h"
#include "../core/game.h"

Camera::Camera():
rect(0, 0, Screen::WIDTH, Screen::HEIGHT)
{
}

void Camera::update() {
    Game::get()->screen.move(this->rect.x, this->rect.y);
}

