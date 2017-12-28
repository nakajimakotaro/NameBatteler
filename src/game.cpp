//
// Created by harus on 2017/12/22.
//

#include <iostream>
#include "game.h"
#include "noneScene.h"
#include "gameingScene.h"
#include <cmath>
#include <utility>

std::unique_ptr<Game> Game::instance;

std::unique_ptr<Game>& Game::get(){
    if(!Game::instance){
        Game::instance.reset(new Game());
    }
    return Game::instance;
}
Game::Game():
        fps(30),
        scene(std::make_shared<GameingScene>())
{
}

int Game::loop(){
    while(true){
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
    return 0;
}

void Game::changeScene(std::shared_ptr<Scene> scene) {
    this->nextScene = std::move(scene);
}

