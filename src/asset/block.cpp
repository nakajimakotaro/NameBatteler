//
// Created by nakajimakotaro on 2018/01/02.
//

#include "block.h"
#include "../core/game.h"


Block::Block():
        GameObject({}, 10 ,41)
{
    isCollision = false;
}
void Block::start(){
    isCollision = false;
    std::shared_ptr<Collider> collider = std::make_shared<Collider>(shared_from_this(), 0, 0, 1, 1, [this](auto obj, auto overarea){ });
    Game::get()->scene->collision.addObjectRequire(collider);
}
void Block::draw() {
    Game::get()->screen.writeChar(isCollision ? '+' : '-', this->x(), this->y());
}


