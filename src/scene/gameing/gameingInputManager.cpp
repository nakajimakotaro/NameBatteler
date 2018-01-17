//
// Created by harus on 2017/12/29.
//

#include <algorithm>
#include "gameingInputManager.h"
#include "../../core/game.h"
#include "../../asset/player.h"

GameingInputManager::GameingInputManager(std::weak_ptr<GameingScene> scene):scene(scene) {

}
void GameingInputManager::update() {
    InputManager::update();
    if(this->isPush(InputManager::LIST::KEY_ESCAPE)) {
        Game::get()->exitRequire();
    }
    if(this->isPush(InputManager::LIST::KEY_R)) {
        this->scene.lock()->reset();
    }
    static bool pushingD = false;
    if(this->isPush(InputManager::LIST::KEY_D)) {
        if(!pushingD){
            this->scene.lock()->pause();
            pushingD = true;
        }
    }else{
        pushingD = false;
    }
}

