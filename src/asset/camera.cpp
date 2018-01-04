//
// Created by nakajimakotaro on 2018/01/02.
//

#include <algorithm>
#include "camera.h"
#include "../core/screen.h"
#include "../core/game.h"
#include "player.h"

Camera::Camera():
GameObject({}, 0 ,0)
{
}


void Camera::start() {
    this->player = Game::get()->scene->getObject<Player>(GameObject::Type::PLAYER);
}
void Camera::update() {
    this->localX = this->player.lock()->x() - 120;
    Game::get()->screen.move(this->x(), this->y());
}

