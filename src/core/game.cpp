//
// Created by harus on 2017/12/22.
//

#include "game.h"
#include "../scene/gameing/gameingScene.h"
#include "../scene/gameing/gameingInputManager.h"
#include "../scene/start/startScene.h"
#include "../scene/scene.h"

std::unique_ptr<Game> Game::instance;

std::unique_ptr<Game>& Game::get(){
    if(!Game::instance){
        Game::instance.reset(new Game());
    }
    return Game::instance;
}
Game::Game():
        fps(30)
{
    auto p = new NoneScene();
    this->scene = std::shared_ptr<Scene>(p);
    this->nextScene = std::make_shared<StartScene>();
    //this->nextScene = std::make_shared<GameingScene>("test", "../map/map.json");
}

int Game::loop(){
    while(!this->isExitRequire){
        if(this->nextScene){
            this->scene->endScene();
            this->scene = this->nextScene;
            this->scene->startScene();
            this->nextScene.reset();
        }

        this->scene->update();
        this->scene->draw();
        this->screen.swap();
        this->fps.wait();
    }
    this->scene->endScene();
    return 0;
}

void Game::changeScene(std::shared_ptr<Scene> scene) {
    this->nextScene = std::move(scene);
    this->screen.move(0, 0);
}

void Game::exitRequire() {
    this->isExitRequire = true;
}

