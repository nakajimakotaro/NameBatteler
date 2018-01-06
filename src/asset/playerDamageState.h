//
// Created by nakajimakotaro on 2018/01/05.
//

#ifndef NAMEBATTLER_PLAYERDAMAGESTATE_H
#define NAMEBATTLER_PLAYERDAMAGESTATE_H


#include "../common/state.h"
#include "../common/stateMachine.h"

class Player;
class PlayerDamageState : public State<Player>{
public:
    static const std::string name(){
        return "damage";
    };
    static StateMapPair<Player> mapPair();
    std::shared_ptr<Player> body();
    explicit PlayerDamageState(std::weak_ptr<StateMachine<Player>> machine);
    void update() override;
};



#endif //NAMEBATTLER_PLAYERDAMAGESTATE_H
