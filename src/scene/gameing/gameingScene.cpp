//
// Created by harus on 2017/12/28.
//

#include "gameingScene.h"
#include "../../asset/player.h"
#include "../../asset/camera.h"
#include "../../asset/block.h"
#include "../../asset/debugMessage.h"

GameingScene::GameingScene()
{
}

void GameingScene::startScene() {
    this->addObject(std::make_shared<DebugMessage>());
    this->addObject(std::make_shared<Camera>());
    this->addObject(Player::create());
    this->addObject(std::make_shared<Block>());
}

void GameingScene::update() {
    if(!this->addQueueList.empty()){
        for(auto obj: this->addQueueList){
            this->objectList.push_back(obj);
        }
        for(auto obj: this->addQueueList){
            obj->start();
        }
        this->addQueueList.clear();
    }
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

void GameingScene::addObject(std::shared_ptr<GameObject> obj){
    this->addQueueList.push_back(obj);
}
