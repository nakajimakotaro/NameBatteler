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
std::shared_ptr<GameObject> GameingScene::getObject(GameObject::Type type){
    return *std::find_if(this->objectList.begin(), this->objectList.end(),
                         [type](auto obj){
                             return obj->getType() == type;
                         });
}

std::vector<std::shared_ptr<GameObject>> GameingScene::getObjectAll(GameObject::Type type){
    std::vector<std::shared_ptr<GameObject>> res;
    auto begin = this->objectList.begin();
    while (true) {
        begin = std::find_if(begin, this->objectList.end(),
                             [type](auto obj) {
                                 return obj->getType() == type;
                             });
        if (begin != this->objectList.end()) {
            res.push_back(*begin);
            begin++;
        } else {
            break;
        }
    }
    return res;
}
