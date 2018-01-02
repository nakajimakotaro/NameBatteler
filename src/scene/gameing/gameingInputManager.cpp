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
}
