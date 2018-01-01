#include "player.h"//
// Created by nakajimakotaro on 2017/12/30.
//

#ifndef NAMEBATTLER_PLAYERJUMPSTATE_H
#define NAMEBATTLER_PLAYERJUMPSTATE_H


#include "../common/state.h"
#include "player.h"
#include "playerRunState.h"

class PlayerJumpState: public State<Player>{
public:
    static const std::string name(){
        return "jump";
    };
    static StateMapPair<Player> mapPair();
    explicit PlayerJumpState(std::weak_ptr<StateMachine<Player>> machine);
    void update() override {};
};


#endif //NAMEBATTLER_PLAYERJUMPSTATE_H
