//
// Created by harus on 2017/12/22.
//

#ifndef NAMEBATTLER_COMMANDMANAGER_H
#define NAMEBATTLER_COMMANDMANAGER_H


enum class Direction {
    TOP,
    DOWN,
    LEFT,
    RIGHT,
};

class CommandManager {
    void processCommand(char command);
    void playerMove(Direction dir);
};


#endif //NAMEBATTLER_COMMANDMANAGER_H
