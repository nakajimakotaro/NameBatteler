//
// Created by nakajimakotaro on 2018/01/02.
//

#include "block.h"
#include "../core/game.h"
#include "debugMessage.h"


Block::Block(double x, double y, double w, double h):
        GameObject(x ,y),
        w(w),
        h(h)
{
}


void Block::start(){
    this->collider = std::shared_ptr<Collider>(new Collider(0, 0, w, h, [](auto obj, auto overarea){}));
    this->addChild(this->collider);
    Game::get()->scene->addObject(this->collider);
    Game::get()->scene->collision.addObjectRequire(this->collider);
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

Block::~Block() {
    Game::get()->scene->removeObject(this->collider);
    Game::get()->scene->collision.removeObjectRequire(this->collider);
}

