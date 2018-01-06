//
// Created by nakajimakotaro on 2017/12/30.
//

#include "player.h"
#include "playerRunState.h"
#include "../scene/inputManager.h"
#include "../core/game.h"

#include <utility>

StateMapPair<Player> PlayerRunState::mapPair() {
    return std::make_pair(
            PlayerRunState::name(),
            [](auto machine){
                return std::unique_ptr<State<Player>>(new PlayerRunState(machine));
            }
    );
}
std::shared_ptr<Player> PlayerRunState::body() {
    return this->machine.lock()->body.lock();
}
PlayerRunState::PlayerRunState(std::weak_ptr<StateMachine<Player>> machine):
        State<Player>(std::move(machine))
{
}

void PlayerRunState::update() {
    this->machine.lock()->body.lock()->localX -= this->machine.lock()->body.lock()->speed;

    if(Game::get()->scene->inputManager.isPush(InputManager::LIST::KEY_SPACE)) {
        this->machine.lock()->changeRequire("jump");
    }

    if(this->countFrame % 30 == 0){
        this->body()->speed += 0.4;
    }
    this->countFrame++;
}


