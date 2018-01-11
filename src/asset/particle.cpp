//
// Created by harus on 2018/01/08.
//

#include "particle.h"
#include "../core/screen.h"
#include "../core/game.h"
#include "../common/gameObject.h"

Particle::Particle(double x, double y):
        GameObject(x, y),
        countFrame(0)
{
}

void Particle::update() {
    this->countFrame++;
}
void Particle::draw() {
    for(int i = 0;i < 4;i++){
        double x, y;
        double a  = std::cos((i / 4.0) * M_PI * 2);
        x = std::cos((i / 4.0) * M_PI * 2 + this->countFrame / 30.0) * this->countFrame / 10;
        y = std::sin((i / 4.0) * M_PI * 2 + this->countFrame / 30.0) * this->countFrame / 10;

        x += this->localX;
        y += this->localY;
        Game::get()->screen.writeChar('*', x, y, Screen::ForColor::RED, Screen::BackColor::CYAN, -10);
    }
}

