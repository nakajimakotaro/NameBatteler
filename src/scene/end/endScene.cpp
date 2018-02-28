//
// Created by nakajimakotaro on 2018/01/26.
//

#include "endScene.h"
#include "../../core/game.h"
#include "../../asset/nameInput.h"
#include <string>

EndScene::EndScene(std::string name):name(name) {
}


void EndScene::startScene() {
    Game::get()->screen.move(0, 0);
}

void EndScene::update() {
    Game::get()->screen.writeString("Congrats!", 77, 24);
    Game::get()->screen.writeString(this->name, 77, 26);
}

void EndScene::draw() {
}

