//
// Created by nakajimakotaro on 2018/01/02.
//

#include "block.h"
#include "../core/game.h"
#include "debugMessage.h"
#include "../scene/gameing/gameingScene.h"



Block::Block(std::weak_ptr<Scene> scene, nlohmann::json json):
        GameObject(scene, json["x"].get<double>(), json["y"].get<double>()),
        w(json["w"].get<double>()),
        h(json["h"].get<double>())
{

}



void Block::start(){
    this->collider = std::shared_ptr<Collider>(new Collider(this->scene, 0, 0, w, h, [](auto obj, auto overarea){}));
    this->addChild(this->collider);
    this->scene.lock()->addObject(this->collider);
    this->scene.lock()->collision.addObjectRequire(this->collider);
}
void Block::update() {
}
void Block::draw() {
    for(int x = this->x();x < this->x() + this->w;x++){
        Game::get()->screen.writeChar('-', x, this->y());
        Game::get()->screen.writeChar('-', x, this->y() + this->h - 1);
    }
    for(int y = this->y() + 1;y < this->y() + this->h - 1;y++){
        Game::get()->screen.writeChar('|', this->x(), y);
        Game::get()->screen.writeChar('|', this->x() + this->w - 1, y);
    }
}

void Block::end() {
    this->scene.lock()->removeObject(this->collider);
    this->scene.lock()->collision.removeObjectRequire(this->collider);
}

