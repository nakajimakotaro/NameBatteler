//
// Created by nakajimakotaro on 2017/12/30.
//

#include "playerJumpState.h"

#include <cmath>
#include "block.h"

StateMapPair<Player> PlayerJumpState::mapPair() {
    return std::make_pair(
            PlayerJumpState::name(),
            [](auto machine){
                return std::unique_ptr<State<Player>>(new PlayerJumpState(machine));
            }
    );
}
std::shared_ptr<Player> PlayerJumpState::body() {
    return this->machine.lock()->body.lock();
}

PlayerJumpState::PlayerJumpState(std::weak_ptr<StateMachine<Player>> machine):
        State<Player>(std::move(machine))
{
}

void PlayerJumpState::start() {
}
void PlayerJumpState::update() {
    this->body()->localX -= this->body()->speed;
    double risingY = cos(this->countFrame / 30.0 * M_PI) * 2;
    if(risingY < 0.1){
        this->machine.lock()->changeRequire("fall");
    }
    this->body()->localY -= risingY;

    this->countFrame++;
}

void PlayerJumpState::end() {
}


