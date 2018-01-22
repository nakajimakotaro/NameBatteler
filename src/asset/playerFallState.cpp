//
// Created by nakajimakotaro on 2018/01/05.
//

#include <cmath>
#include "player.h"
#include "playerFallState.h"
#include "block.h"
#include "../core/game.h"

StateMapPair<Player> PlayerFallState::mapPair() {
    return std::make_pair(
            PlayerFallState::name(),
            [](auto machine){
                return std::unique_ptr<State<Player>>(new PlayerFallState(machine));
            }
    );
}

PlayerFallState::PlayerFallState(std::weak_ptr<StateMachine<Player>> machine) : State(machine) {
}


void PlayerFallState::start() {
}
void PlayerFallState::update() {
    if(Game::get()->scene->input.isPush(InputManager::LIST::KEY_A)){
        this->body_ptr()->localX -= this->body_ptr()->speed;
    }
    if(Game::get()->scene->input.isPush(InputManager::LIST::KEY_D)){
        this->body_ptr()->localX += this->body_ptr()->speed;
    }
    if(this->countFrame > 1 && this->body_ptr()->rideCollisionBlock){
        this->body_ptr()->localY = this->body_ptr()->rideCollisionBlock->y() - this->body_ptr()->range;
        this->machine.lock()->changeRequire("run");
        return;
    }

    double fallY;
    if(this->countFrame < 15){
        fallY = sin((this->countFrame / 30.0) * M_PI) * 2;
    }else{
        fallY = 1;
    }

    this->body_ptr()->localY += fallY;
    this->countFrame++;
}

void PlayerFallState::end() {
}
