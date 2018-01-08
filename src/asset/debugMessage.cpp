//
// Created by nakajimakotaro on 2018/01/02.
//

#include "debugMessage.h"
#include "../core/game.h"

DebugMessage::DebugMessage():
GameObject(0, 0)
{

}
void DebugMessage::update() {
    this->localX = Game::get()->screen.rect.x;
}

void DebugMessage::draw() {
    auto strFPS = std::to_string(Game::get()->fps.fps());
    Game::get()->screen.writeString(strFPS, this->x(), this->y());
    int i = 1;
    for(auto message: this->messageList){
        Game::get()->screen.writeString(message.first + ": " + message.second, this->x(), this->y() + i);
        i++;
    }
}

GameObject::Type DebugMessage::getType() {
    return GameObject::Type::DEBUG_MESSAGE;
}

void DebugMessage::set(std::string name, std::string value) {
    auto message = std::find_if(this->messageList.begin(), this->messageList.end(), [name](std::pair<std::string, std::string> obj){
        return obj.first == name;
    });
    if(message == this->messageList.end()){
        this->messageList.emplace_back(name, value);
    }else{
        (*message).second = value;
    }
}

