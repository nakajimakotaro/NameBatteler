//
// Created by harus on 2017/12/28.
//

#include <algorithm>
#include "gameingScene.h"
#include "../../asset/player.h"
#include "../../asset/camera.h"
#include "../../asset/enemy.h"
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
    this->addObject(std::make_shared<Block>(-40, -1, 100, 31));
    this->addObject(std::make_shared<Block>(-50, 40, 100, 30));
    this->addObject(std::make_shared<Block>(-150, 30, 90, 30));
    this->addObject(std::make_shared<Block>(-300, 30, 130, 31));
    this->addObject(std::make_shared<Block>(-300, 30, 130, 31));
    this->addObject(std::make_shared<Enemy>(-30, 37));
    this->addObject(std::make_shared<Enemy>(-120, 17));
}

void GameingScene::queueUpdate(){
    auto removeQueueList = this->removeQueueList;
    this->removeQueueList.clear();
    //removeQueue�̃I�u�W�F�N�g���폜
    for(auto& removeObject: removeQueueList) {
        removeObject->end();
    }
    for(auto& removeObject: removeQueueList){
        auto index = std::distance(this->objectList.begin(), std::find(this->objectList.begin(), this->objectList.end(), removeObject));
        this->objectList[index] = *(this->objectList.end() - 1);
        this->objectList.pop_back();
    }

    auto addQueueList = this->addQueueList;
    this->addQueueList.clear();
    //addQueue�̃I�u�W�F�N�g��ǉ�
    for(const auto &obj: addQueueList){
        this->objectList.push_back(obj);
    }
    for(const auto &obj: addQueueList){
        obj->start();
    }
}

void GameingScene::update() {
    this->inputManager.update();

    if(!this->isPause){
        this->queueUpdate();
        this->collision.tick();
        for(const auto &object: this->objectList){
            object->update();
        }
        for(const auto &object: this->objectList){
            object->postUpdate();
        }
    }
}

void GameingScene::draw() {
    for(const auto &object: this->objectList){
        object->draw();
    }
}

void GameingScene::endScene() {
}

void GameingScene::pause(){
    this->isPause = !this->isPause;
}

std::shared_ptr<GameObject> GameingScene::addObject(std::weak_ptr<GameObject> obj){
    this->addQueueList.push_back(obj.lock());
    return obj.lock();
}

std::shared_ptr<GameObject> GameingScene::removeObject(std::weak_ptr<GameObject> obj) {
    this->removeQueueList.push_back(obj.lock());
    return obj.lock();
}


void GameingScene::reset() {
    this->objectList.clear();
    this->addQueueList.clear();
    this->removeQueueList.clear();
    this->collision = Collision();
    this->startScene();
}
