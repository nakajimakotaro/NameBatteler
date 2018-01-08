//
// Created by harus on 2017/12/29.
//

#include <algorithm>
#include "gameingInputManager.h"
#include "../../core/game.h"
#include "../../asset/player.h"

void GameingInputManager::update() {
    if(this->isPush(InputManager::LIST::KEY_ESCAPE)) {
        Game::get()->exitRequire();
    }
    if(this->isPush(InputManager::LIST::KEY_R)) {
        Game::get()->scene->reset();
    }
    static bool pushingD = false;
    if(this->isPush(InputManager::LIST::KEY_D)) {
        if(!pushingD){
            Game::get()->scene->pause();
            pushingD = true;
        }
    }else{
        pushingD = false;
    }
}
