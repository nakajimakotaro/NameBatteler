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

void Camera::update() {
    this->rect.x = this->player.lock()->rect.x - 120;
    Game::get()->screen.move(this->rect.x, this->rect.y);
}

void Camera::start() {
    auto _player = *std::find_if(Game::get()->scene->objectList.begin(), Game::get()->scene->objectList.end(),
                 [](auto obj){
                     return obj->getType() == GameObject::Type::PLAYER;
                 });
    this->player = reinterpret_cast<std::shared_ptr<Player>&>(_player);
}

