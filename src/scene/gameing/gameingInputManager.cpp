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
    if(this->isPush(InputManager::LIST::KEY_SPACE)) {
        auto _player = *std::find_if(Game::get()->scene->objectList.begin(), Game::get()->scene->objectList.end(),
                                     [](auto obj){
                                         return obj->getType() == GameObject::Type::PLAYER;
                                     });
        reinterpret_cast<std::shared_ptr<Player>&>(_player);
    }
}
