//
// Created by nakajimakotaro on 2017/12/30.
//

#include "player.h"
#include "playerRunState.h"

#include <utility>

StateMapPair<Player> PlayerRunState::mapPair() {
    return std::make_pair(
            PlayerRunState::name(),
            [](auto machine){
                return std::unique_ptr<State<Player>>(new PlayerRunState(machine));
            }
    );
}
PlayerRunState::PlayerRunState(std::weak_ptr<StateMachine<Player>> machine):
        State<Player>(std::move(machine))
{
}

void PlayerRunState::update() {
    this->machine.lock()->body.lock()->rect.x -= 1;
}


