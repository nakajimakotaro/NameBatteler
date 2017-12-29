//
// Created by harus on 2017/12/29.
//

#ifndef NAMEBATTLER_STATEMACHINE_H
#define NAMEBATTLER_STATEMACHINE_H


#include <map>
#include "state.h"

struct StateEvent{
    std::string name;
    std::string from;
    std::string to;
};

class StateMachine {
public:
    State state;
    std::map<std::string, StateEvent> eventList;
    StateMachine(std::string initState, std::map<std::string, StateEvent> eventList);
    void next(std::string name);

};


#endif //NAMEBATTLER_STATEMACHINE_H
