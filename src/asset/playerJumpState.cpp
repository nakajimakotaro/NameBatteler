//
// Created by nakajimakotaro on 2017/12/30.
//

#include "playerJumpState.h"

#include <utility>

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

