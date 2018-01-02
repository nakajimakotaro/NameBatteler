//
// Created by nakajimakotaro on 2017/12/30.
//

#include "playerJumpState.h"

#include <utility>
#include <cmath>

StateMapPair<Player> PlayerJumpState::mapPair() {
    return std::make_pair(
            PlayerJumpState::name(),
            [](auto machine){
                return std::unique_ptr<State<Player>>(new PlayerJumpState(machine));
            }
    );
}

PlayerJumpState::PlayerJumpState(std::weak_ptr<StateMachine<Player>> machine):
        State<Player>(std::move(machine))
{
}

void PlayerJumpState::start() {
    this->baseY = this->machine.lock()->body.lock()->rect.y;
}
void PlayerJumpState::update() {
    this->machine.lock()->body.lock()->rect.x -= this->machine.lock()->body.lock()->speed;
    this->machine.lock()->body.lock()->rect.y = this->baseY - sin(this->countFrame / 30.0 * 3.1415) * 20;
    if(this->countFrame > 30){
        this->machine.lock()->changeRequire("run");
    }

    this->countFrame++;
}

void PlayerJumpState::end() {
    this->machine.lock()->body.lock()->rect.y = this->baseY;
}
