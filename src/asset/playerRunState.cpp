//
// Created by nakajimakotaro on 2017/12/30.
//

#include "player.h"
#include "playerRunState.h"
#include "../scene/inputManager.h"
#include "../core/game.h"
#include "moveParticle.h"
#include "../scene/gameing/gameingInputManager.h"
#include "../scene/gameing/gameingScene.h"
#include <utility>
#include "../common/gameObject.h"
#include "block.h"
#include "moveBlock.h"


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


void PlayerRunState::start() {
}

void PlayerRunState::update() {
    if(Game::get()->scene->input.isPush(InputManager::LIST::KEY_A)){
        this->body_ptr()->localX -= this->body_ptr()->speed;
    }
    if(Game::get()->scene->input.isPush(InputManager::LIST::KEY_D)){
        this->body_ptr()->localX += this->body_ptr()->speed;
    }

    if(Game::get()->scene->input.isPush(InputManager::LIST::KEY_SPACE)) {
        this->machine.lock()->changeRequire("jump");
    }
    if(!this->body_ptr()->rideCollisionBlock){
        this->machine.lock()->changeRequire("fall");
    }
    if(this->body_ptr()->rideCollisionBlock && this->body_ptr()->rideCollisionBlock->getType() == GameObject::Type::MOVEBLOCK){
        this->body_ptr()->localX += std::dynamic_pointer_cast<MoveBlock>(this->body_ptr()->rideCollisionBlock)->prevMoveX;
        this->body_ptr()->localY += std::dynamic_pointer_cast<MoveBlock>(this->body_ptr()->rideCollisionBlock)->prevMoveY;
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
        x += this->body_ptr()->bottomX();
        y += this->body_ptr()->bottomY();
        Game::get()->screen.writeChar('-', x, y, Screen::ForColor::WHILE, Screen::BackColor::YELLOW, 10);
    }
}
void PlayerRunState::end() {
}
