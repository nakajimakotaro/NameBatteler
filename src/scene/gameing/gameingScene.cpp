//
// Created by harus on 2017/12/28.
//

#include "gameingScene.h"
#include "../../asset/player.h"

GameingScene::GameingScene()
{
    this->objectList.push_back(Player::create());
}

void GameingScene::startScene() {
}

void GameingScene::update() {
    this->inputManager.update();
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

