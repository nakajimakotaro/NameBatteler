//
// Created by harus on 2017/12/22.
//

#include "commandManager.h"

void CommandManager::processCommand(char command) {
    switch(command){
        case 'w':
            this->playerMove(Direction::TOP);
            break;
        case 's':
            this->playerMove(Direction::DOWN);
            break;
        case 'a':
            this->playerMove(Direction::LEFT);
            break;
        case 'd':
            this->playerMove(Direction::RIGHT);
            break;
        default:
            break;
    }
}
void CommandManager::playerMove(Direction dir){
}
