//
// Created by nakajimakotaro on 2018/01/11.
//

#include "dotBullet.h"
#include "../core/game.h"
DotBullet::DotBullet(double x, double y, GameObject::Type shotOwner) : Bullet(x, y, shotOwner) {

}

void DotBullet::start() {
    this->collider = std::shared_ptr<Collider>(new Collider(0, 0, 1, 1, [](auto a, auto b){}));
    this->addChild(this->collider);
    Game::get()->scene->collision.addObjectRequire(this->collider);
    Game::get()->scene->addObject(this->collider);
}

void DotBullet::update() {
}

void DotBullet::draw() {
    Game::get()->screen.writeChar(this->text, this->x(), this->y(), this->forColor, this->backColor, this->layer);
}

void DotBullet::end() {
    Game::get()->scene->collision.removeObjectRequire(this->collider);
    Game::get()->scene->removeObject(this->collider);
}

