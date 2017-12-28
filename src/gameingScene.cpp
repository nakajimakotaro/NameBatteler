//
// Created by harus on 2017/12/28.
//

#include "gameingScene.h"
#include "player.h"

GameingScene::GameingScene()
{
    this->objectList.push_back(std::make_unique<Player>());
}

void GameingScene::startScene() {
}

void GameingScene::update() {
    for(const auto &object: this->objectList){
        object->update();
    }
}

void GameingScene::draw() {
    for(const auto &object: this->objectList){
        object->draw();
    }
}

void GameingScene::endScene() {

}

