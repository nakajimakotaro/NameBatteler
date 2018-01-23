//
// Created by harus on 2018/01/12.
//

#include "arrowBullet.h"
#include "../core/game.h"

ArrowBullet::ArrowBullet(std::weak_ptr<Scene> scene, double x, double y, GameObject::Type ownerType, double angle) :
        Bullet(scene, x, y, ownerType),
        angle(angle)
{

}

void ArrowBullet::start() {
}

void ArrowBullet::update() {
    double speed = 3;
    this->localX += cos(this->angle) * speed;
    this->localY += sin(this->angle) * speed;
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

