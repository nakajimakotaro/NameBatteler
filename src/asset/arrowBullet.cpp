//
// Created by harus on 2018/01/12.
//

#include "arrowBullet.h"
#include "../core/game.h"

ArrowBullet::ArrowBullet(std::weak_ptr<GameingScene> scene, double x, double y, GameObject::Type ownerType) : Bullet(scene, x, y, ownerType) {
}

void ArrowBullet::start() {
}

void ArrowBullet::update() {
    this->localX -= 3;
}

void ArrowBullet::draw() {
    int count = Game::get()->fps.getCountFrame();
    Game::get()->screen.writeChar(count % 10 > 4 ? '/' : '\\', this->x() - 1, this->y() - 1);
    Game::get()->screen.writeChar(count % 10 < 4 ? '/' : '\\', this->x() + 1, this->y() - 1);
    Game::get()->screen.writeChar(count % 10 > 4 ? '/' : '\\', this->x() + 1, this->y() + 1);
    Game::get()->screen.writeChar(count % 10 < 4 ? '/' : '\\', this->x() - 1, this->y() + 1);
    Game::get()->screen.writeChar('*', this->x() - 0, this->y() + 0, Screen::ForColor::MAGENTA, Screen::BackColor::YELLOW);
}

void ArrowBullet::end() {
}
