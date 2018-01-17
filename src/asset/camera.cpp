//
// Created by nakajimakotaro on 2018/01/02.
//

#include <algorithm>
#include "camera.h"
#include "../core/screen.h"
#include "../core/game.h"
#include "player.h"
#include "../scene/gameing/gameingScene.h"

Camera::Camera(std::weak_ptr<GameingScene> scene):
GameObject(scene, 0 ,0)
{
}


void Camera::start() {
    this->player = this->scene.lock()->getObject<Player>(GameObject::Type::PLAYER);
}
void Camera::set() {
    this->localX = std::floor(this->player.lock()->x() - 120);
    Game::get()->screen.move(this->x(), this->y());
}

