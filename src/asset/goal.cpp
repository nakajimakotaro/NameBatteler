//
// Created by nakajimakotaro on 2018/01/25.
//

#include "goal.h"
#include "../core/game.h"

Goal::Goal(std::weak_ptr<Scene> scene, double localX, double localY) : GameObject(scene, localX, localY) {
}
Goal::Goal(std::weak_ptr<Scene> scene, std::shared_ptr<MyJson::JsonInterFace> json):
       Goal(scene, json("x")->getInt(), json("y")->getInt())
{
}


void Goal::start() {
    auto rideCollider = std::shared_ptr<Collider>(new Collider(this->scene, -3, -7, 6, 14, [this](auto obj, auto overarea){ }));
    this->addChild(rideCollider);
    this->scene.lock()->collision.addObjectRequire(rideCollider);
}
void Goal::update() {
}

void Goal::draw() {
    for(int i = -3;i <= 3;i++){
        Game::get()->screen.writeChar('-', this->x() + i, this->y() - 7, Screen::ForColor::MAGENTA);
        Game::get()->screen.writeChar('-', this->x() + i, this->y() + 7, Screen::ForColor::MAGENTA);
        Game::get()->screen.writeChar('*', this->x() + i, this->y() + 0, Screen::ForColor::MAGENTA);
    }
    for(int i = -6;i <= 6;i++){
        Game::get()->screen.writeChar('|', this->x() + 3, this->y() + i, Screen::ForColor::MAGENTA);
        Game::get()->screen.writeChar('|', this->x() - 3, this->y() + i, Screen::ForColor::MAGENTA);
        Game::get()->screen.writeChar('*', this->x() + 0, this->y() + i, Screen::ForColor::MAGENTA);
    }
}
