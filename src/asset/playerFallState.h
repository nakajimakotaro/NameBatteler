//
// Created by nakajimakotaro on 2018/01/05.
//

#ifndef NAMEBATTLER_PLAYERFALLSTATE_H
#define NAMEBATTLER_PLAYERFALLSTATE_H

#include "../common/state.h"
#include "../common/stateMachine.h"

class Player;
class PlayerFallState : public State<Player>{
private:
    std::shared_ptr<Player> body();
public:
    int countFrame = 0;
    double baseY = 0;
    static const std::string name(){
        return "fall";
    };
    static StateMapPair<Player> mapPair();
    explicit PlayerFallState(std::weak_ptr<StateMachine<Player>> machine);
    void start() override ;
    void update() override;
    void end() override;
};


#endif //NAMEBATTLER_PLAYERFALLSTATE_H
