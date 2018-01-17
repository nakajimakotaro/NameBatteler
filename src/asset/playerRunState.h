//
// Created by nakajimakotaro on 2017/12/30.
//

#ifndef NAMEBATTLER_PLAYERRUNSTATE_H
#define NAMEBATTLER_PLAYERRUNSTATE_H


#include "../common/state.h"
#include "../common/stateMachine.h"

class Player;
class PlayerRunState: public State<Player>{
public:
    static const std::string name(){
        return "run";
    };
    explicit PlayerRunState(std::weak_ptr<StateMachine<Player>> machine);

    static StateMapPair<Player> mapPair();
    std::shared_ptr<Player> body();
    void start() override;
    void update() override;
    void draw() override;
    void end() override;
    int countFrame;
};



#endif //NAMEBATTLER_PLAYERRUNSTATE_H
