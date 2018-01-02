//
// Created by nakajimakotaro on 2018/01/02.
//

#include "debugMessage.h"
#include "../core/game.h"

DebugMessage::DebugMessage():
        rect(0, 0, 80, 1)
{

}
void DebugMessage::update() {
    this->rect.x = Game::get()->screen.rect.x;
}

void DebugMessage::draw() {
    auto strFPS = std::to_string(Game::get()->fps.fps());
    Game::get()->screen.writeString(strFPS, this->rect.x, this->rect.y);
}

GameObject::Type DebugMessage::getType() {
    return GameObject::Type::DEBUG_MESSAGE;
}

