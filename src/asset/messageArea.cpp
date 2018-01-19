//
// Created by harus on 2017/12/23.
//

#include "messageArea.h"
#include "../core/game.h"


MessageArea::MessageArea(std::weak_ptr<Scene> scene):
        GameObject(scene, 0, 0)
{
}
void MessageArea::message(const char* str){
    Game::get()->screen.writeString(str, this->x(), this->y());
}

void MessageArea::update() {

}

void MessageArea::draw() {

}

GameObject::Type MessageArea::getType() {
    return GameObject::Type::MESSAGE_AREA;
}

