//
// Created by nakajimakotaro on 2018/01/02.
//

#include <algorithm>
#include "camera.h"
#include "../core/screen.h"
#include "../core/game.h"
#include "player.h"

Camera::Camera():
        rect(0, 0, Screen::WIDTH, Screen::HEIGHT)
{
}


void Camera::start() {
    this->player = Game::get()->scene->getObject<Player>(GameObject::Type::PLAYER);
}
void Camera::update() {
    this->rect.x = this->player.lock()->rect.x - 120;
    Game::get()->screen.move(this->rect.x, this->rect.y);
}

