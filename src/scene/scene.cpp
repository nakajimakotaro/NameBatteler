//
// Created by harus on 2018/01/18.
//
#include <memory>
#include "scene.h"

std::shared_ptr<GameObject> Scene::addObject(std::weak_ptr<GameObject> obj) {
    this->addQueueList.push_back(obj.lock());
    return obj.lock();
}

std::shared_ptr<GameObject> Scene::removeObject(std::weak_ptr<GameObject> obj) {
    this->removeQueueList.push_back(obj.lock());
    return obj.lock();
}

void Scene::queueUpdate(){
    auto removeQueueList = this->removeQueueList;
    this->removeQueueList.clear();
    //removeQueueのオブジェクトを削除
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
    //addQueueのオブジェクトを追加
    for(const auto &obj: addQueueList){
        this->objectList.push_back(obj);
    }
    for(const auto &obj: addQueueList){
        obj->start();
    }
}
