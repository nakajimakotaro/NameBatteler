//
// Created by nakajimakotaro on 2018/01/02.
//

#include "block.h"
#include "../core/game.h"

Block::Block():
rect(10, 41, 1, 1)
{

}
void Block::draw() {
    Game::get()->screen.writeChar('-', this->rect.x, this->rect.y);
}

