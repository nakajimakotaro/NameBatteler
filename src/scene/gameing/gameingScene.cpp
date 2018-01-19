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
#include "gameingInputManager.h"

GameingScene::GameingScene(std::string name):name(name)
{
}

void GameingScene::startScene() {
    auto res = shared_from_this();
    this->inputManager = std::make_unique<GameingInputManager>(std::dynamic_pointer_cast<GameingScene>(shared_from_this()));
    this->addObject(std::make_shared<DebugMessage>(shared_from_this()));
    this->addObject(std::make_shared<Camera>(shared_from_this()));
    this->addObject(Player::create(shared_from_this(), name));
    this->addObject(std::shared_ptr<Block>(new Block(shared_from_this(), -40, -1, 100, 31)));
    this->addObject(std::shared_ptr<Block>(new Block(shared_from_this(), -50, 40, 100, 30)));
    this->addObject(std::shared_ptr<Block>(new Block(shared_from_this(), -150, 30, 90, 30)));
    this->addObject(std::shared_ptr<Block>(new Block(shared_from_this(), -300, 30, 130, 31)));
    this->addObject(std::shared_ptr<Block>(new Block(shared_from_this(), -300, 30, 130, 31)));
    this->addObject(std::shared_ptr<Enemy>(new Enemy(shared_from_this(), -30, 37)));
    this->addObject(std::shared_ptr<Enemy>(new Enemy(shared_from_this(), -120, 17)));
}


void GameingScene::update() {
    this->inputManager->update();
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

void GameingScene::reset() {
    Game::get()->changeScene(std::make_shared<GameingScene>(this->name));
}


