//
// Created by harus on 2017/12/28.
//

#include <algorithm>
#include <fstream>
#include "gameingScene.h"
#include "../../asset/player.h"
#include "../../asset/camera.h"
#include "../../asset/enemy.h"
#include "../../asset/block.h"
#include "../../asset/debugMessage.h"
#include "../../core/game.h"
#include "gameingInputManager.h"
#include "../../common/json.h"
#include "../../asset/moveBlock.h"
#include "../../asset/goal.h"
#include "../end/endScene.h"

GameingScene::GameingScene(std::string name, std::string mapPath):name(name), mapPath(mapPath)
{
}

void GameingScene::startScene() {
    auto res = shared_from_this();
    this->inputManager = std::make_unique<GameingInputManager>(std::dynamic_pointer_cast<GameingScene>(shared_from_this()));
    this->addObject(std::make_shared<DebugMessage>(shared_from_this()));
    this->addObject(std::make_shared<Camera>(shared_from_this()));

    this->load();
}


void GameingScene::update() {
    this->inputManager->update();
    if(!this->isPause){
        this->queueUpdate();
        this->collision.tick();
        for(const auto &object: this->objectList){
            object->update();
        }
        this->getObject<Camera>(GameObject::Type::CAMERA)->set();
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
    Game::get()->changeScene(std::make_shared<GameingScene>(this->name, "map/map.json"));
}
void GameingScene::goal() {
    Game::get()->changeScene(std::make_shared<EndScene>(this->name));
}


void GameingScene::load(){
    MyJson::Json mapData;
    mapData.parseFile(R"(C:\Users\harus\program\NameBatteler\src\map\map.json)");
    int size = std::dynamic_pointer_cast<MyJson::JsonArray>(mapData.get("object"))->size();
    for(int i = 0;i < size;i++){
        if(mapData.get("object", i, "type")->getString() == "player"){
            this->addObject(std::shared_ptr<Player>(new Player(shared_from_this(), mapData.get("object", i, "data"), this->name)));
        }else if(mapData.get("object", i, "type")->getString() == "block") {
            this->addObject(std::shared_ptr<Block>(new Block(shared_from_this(), mapData.get("object", i, "data"))));
        }else if(mapData.get("object", i, "type")->getString() == "moveblock") {
            this->addObject(std::shared_ptr<MoveBlock>(new MoveBlock(shared_from_this(), mapData.get("object", i, "data"))));
        }else if(mapData.get("object", i, "type")->getString() == "enemy") {
            this->addObject(std::shared_ptr<Enemy>(new Enemy(shared_from_this(), mapData.get("object", i, "data"))));
        }else if(mapData.get("object", i, "type")->getString() == "goal") {
            this->addObject(std::shared_ptr<Goal>(new Goal(shared_from_this(), mapData.get("object", i, "data"))));
        }
    }
}

