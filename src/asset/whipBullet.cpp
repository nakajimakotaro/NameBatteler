//
// Created by nakajimakotaro on 2018/01/11.
//

#include "whipBullet.h"
#include "../core/game.h"
#include "../scene/gameing/gameingScene.h"

WhipBullet::WhipBullet(std::weak_ptr<GameingScene> scene, double x, double y, GameObject::Type shotOwner): Bullet(scene, x, y, shotOwner)
{
}

void WhipBullet::start() {
    for(int i = 0;i < 30;i++){
        auto bullet = std::shared_ptr<DotBullet>(new DotBullet(this->scene, 0, 0, this->shotOwner));
        this->addChild(bullet);
        this->scene.lock()->addObject(bullet);
        this->bulletList.push_back(bullet);

        bullet->backColor = Screen::BackColor ::CYAN;
    }
}


void WhipBullet::update() {
    const int lifeTime = 30;
    if(this->countFrame() > lifeTime){
        this->getParent().lock()->removeChild(shared_from_this());
        this->scene.lock()->removeObject(shared_from_this());
        for(auto& bullet: this->bulletList){
            this->scene.lock()->removeObject(bullet);
        }
        return;
    }

    double x, y;
    for(auto IBullet = this->bulletList.begin();IBullet != this->bulletList.end();IBullet++){
        int index = std::distance(this->bulletList.begin(), IBullet);
        auto& bullet = *IBullet;
        double gabage;
        double percent = std::modf(index / 30. + this->countFrame() / 30., &gabage) * M_PI * 2;

        x = -index;
        y = std::sin(percent) * 2;
        bullet->localX = x;
        bullet->localY = y;
    }
}

void WhipBullet::draw() {
}

void WhipBullet::end() {
}

