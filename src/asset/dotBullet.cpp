//
// Created by nakajimakotaro on 2018/01/11.
//

#include "dotBullet.h"
#include "../core/game.h"
#include "../scene/gameing/gameingScene.h"
DotBullet::DotBullet(std::weak_ptr<GameingScene> scene, double x, double y, GameObject::Type shotOwner) : Bullet(scene, x, y, shotOwner) {

}

void DotBullet::start() {
    this->collider = std::shared_ptr<Collider>(new Collider(this->scene, 0, 0, 1, 1, [](auto a, auto b){}));
    this->addChild(this->collider);
    this->scene.lock()->collision.addObjectRequire(this->collider);
    this->scene.lock()->addObject(this->collider);
}

void DotBullet::update() {
}

void DotBullet::draw() {
    Game::get()->screen.writeChar(this->text, this->x(), this->y(), this->forColor, this->backColor, this->layer);
}

void DotBullet::end() {
    this->scene.lock()->collision.removeObjectRequire(this->collider);
    this->scene.lock()->removeObject(this->collider);
}

