//
// Created by nakajimakotaro on 2018/01/11.
//

#include "whipBullet.h"
#include "../core/game.h"

WhipBullet::WhipBullet(double x, double y, GameObject::Type shotOwner): Bullet(x, y, shotOwner)
{
}

void WhipBullet::start() {
    for(int i = 0;i < 30;i++){
        auto bullet = std::shared_ptr<DotBullet>(new DotBullet(0, 0, this->shotOwner));
        this->addChild(bullet);
        Game::get()->scene->addObject(bullet);
        this->bulletList.push_back(bullet);

        bullet->backColor = Screen::BackColor ::CYAN;
    }
}


void WhipBullet::update() {
    double x, y;
    for(auto IBullet = this->bulletList.begin();IBullet != this->bulletList.end();IBullet++){
        int index = std::distance(this->bulletList.begin(), IBullet);
        auto& bullet = *IBullet;
        double percent = (index / 30. + this->countFrame() / 30.) * M_PI * 2;
        x = -index;
        y = std::sin(percent) * 2;
        bullet.lock()->localX = x;
        bullet.lock()->localY = y;
    }
}

void WhipBullet::draw() {
}

void WhipBullet::end() {
    for(auto& bullet: this->bulletList){
        Game::get()->scene->removeObject(bullet);
    }
}

