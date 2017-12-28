//
// Created by harus on 2017/12/29.
//

#include "gameingInputManager.h"
#include "../../core/game.h"

void GameingInputManager::update() {
    if(this->isPush(InputManager::LIST::KEY_ESCAPE)) {
        Game::get()->exitRequire();
    }
    if(this->isPush(InputManager::LIST::KEY_A)) {
        Game::get()->screen.move( 2, 0);
    }
    if(this->isPush(InputManager::LIST::KEY_D)) {
        Game::get()->screen.move(-2, 0);
    }
}
