//
// Created by nakajimakotaro on 2017/12/30.
//

#ifndef NAMEBATTLER_PLAYERJUMPSTATE_H
#define NAMEBATTLER_PLAYERJUMPSTATE_H

#include "../common/state.h"
#include "../common/stateMachine.h"

class Player;
class PlayerJumpState: public State<Player>{
private:
    std::shared_ptr<Player> body();
public:
    int countFrame = 0;
    double baseY = 0;
    static const std::string name(){
        return "jump";
    };
    static StateMapPair<Player> mapPair();
    explicit PlayerJumpState(std::weak_ptr<StateMachine<Player>> machine);
    void start() override ;
    void update() override;
    void end() override;
};


#endif //NAMEBATTLER_PLAYERJUMPSTATE_H
