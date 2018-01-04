//
// Created by nakajimakotaro on 2018/01/05.
//

#include <cmath>
#include "player.h"
#include "playerFallState.h"
#include "block.h"

StateMapPair<Player> PlayerFallState::mapPair() {
    return std::make_pair(
            PlayerFallState::name(),
            [](auto machine){
                return std::unique_ptr<State<Player>>(new PlayerFallState(machine));
            }
    );
}
std::shared_ptr<Player> PlayerFallState::body() {
    return this->machine.lock()->body.lock();
}

PlayerFallState::PlayerFallState(std::weak_ptr<StateMachine<Player>> machine) : State(machine) {

}


void PlayerFallState::start() {
}
void PlayerFallState::update() {
    this->body()->localX -= this->body()->speed;
    if(this->countFrame > 1 && this->body()->collisionBlock){
        this->body()->localY = this->body()->collisionBlock->y() - 1;
        this->machine.lock()->changeRequire("run");
        return;
    }


    double fallY;
    if(this->countFrame < 30){
        fallY = sin(this->countFrame / 30.0 * M_PI) * 2;
    }else{
        fallY = 2;
    }

    this->body()->localY += fallY;
    this->countFrame++;
}

void PlayerFallState::end() {
}
