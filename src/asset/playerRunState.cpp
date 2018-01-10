//
// Created by nakajimakotaro on 2017/12/30.
//

#include "player.h"
#include "playerRunState.h"
#include "../scene/inputManager.h"
#include "../core/game.h"
#include "moveParticle.h"

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


void PlayerRunState::start() {
}

void PlayerRunState::update() {
    this->machine.lock()->body.lock()->localX -= this->machine.lock()->body.lock()->speed;

    if(Game::get()->scene->inputManager.isPush(InputManager::LIST::KEY_SPACE)) {
        this->machine.lock()->changeRequire("jump");
    }
    if(!this->body()->collisionBlock){
        this->machine.lock()->changeRequire("fall");
    }

    this->countFrame++;
}
void PlayerRunState::draw() {
    double x, y;
    const int num = 3;
    const int loopTime = 10;
    const int range = 6;
    for(int i = 0;i < num;i++){
        double garbage;
        const double percent = modf(this->countFrame / (double)loopTime + i / (double)num, &garbage);
        x = std::cos(percent * M_PI) * range;
        y = 1;
        x += this->body()->bottomX();
        y += this->body()->bottomY();
        Game::get()->screen.writeChar('-', x, y, Screen::ForColor::WHILE, Screen::BackColor::YELLOW, 10);
    }
}
void PlayerRunState::end() {
}


