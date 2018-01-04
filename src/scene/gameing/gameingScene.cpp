//
// Created by harus on 2017/12/28.
//

#include <algorithm>
#include "gameingScene.h"
#include "../../asset/player.h"
#include "../../asset/camera.h"
#include "../../asset/block.h"
#include "../../asset/debugMessage.h"
#include "../../core/game.h"

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
        for(const auto &obj: this->addQueueList){
            this->objectList.push_back(obj);
        }
        for(const auto &obj: this->addQueueList){
            obj->start();
        }
        this->addQueueList.clear();
    }
    this->inputManager.update();
    for(const auto &object: this->objectList){
        object->update();
    }
    this->collision.tick();
}

void GameingScene::draw() {
    for(const auto &object: this->objectList){
        object->draw();
    }
}

void GameingScene::endScene() {
}

std::shared_ptr<GameObject> GameingScene::addObject(std::shared_ptr<GameObject> obj){
    this->addQueueList.push_back(obj);
    return obj;
}


void GameingScene::reset() {
    this->objectList.clear();
    this->addQueueList.clear();
    this->collision = Collision();
    this->startScene();
}
