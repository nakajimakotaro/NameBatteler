//
// Created by harus on 2018/01/18.
//

#include "startScene.h"
#include "../../core/game.h"
#include "../../asset/nameInput.h"

void StartScene::startScene() {
    this->addObject(std::shared_ptr<GameObject>(new NameInput(shared_from_this(), 80, 25)));
}

void StartScene::update() {
    this->queueUpdate();

    for(auto object: this->objectList){
        object->update();
    }
}

void StartScene::draw() {
    for(auto object: this->objectList){
        object->draw();
    }
}
