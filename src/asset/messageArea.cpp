//
// Created by harus on 2017/12/23.
//

#include "messageArea.h"
#include "../core/game.h"


MessageArea::MessageArea():
        rect(0, 0, 80, 1)
{
}
void MessageArea::message(const char* str){
    Game::get()->screen.writeString(str, this->rect.x, this->rect.y, 0, this->rect);
}

void MessageArea::update() {

}

void MessageArea::draw() {

}

GameObject::Type MessageArea::getType() {
    return GameObject::Type::MESSAGE_AREA;
}

