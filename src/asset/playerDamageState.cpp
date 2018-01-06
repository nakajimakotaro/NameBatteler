//
// Created by nakajimakotaro on 2018/01/05.
//

#include "playerDamageState.h"
#include "player.h"
#include "../core/game.h"

StateMapPair<Player> PlayerDamageState::mapPair() {
    return std::make_pair(
            PlayerDamageState::name(),
            [](auto machine){
                return std::unique_ptr<State<Player>>(new PlayerDamageState(machine));
            }
    );
}
std::shared_ptr<Player> PlayerDamageState::body() {
    return this->machine.lock()->body.lock();
}
PlayerDamageState::PlayerDamageState(std::weak_ptr<StateMachine<Player>> machine):
        State<Player>(std::move(machine))
{
}

void PlayerDamageState::update() {
    this->body()->speed -= 1;
}

