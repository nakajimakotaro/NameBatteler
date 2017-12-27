//
// Created by harus on 2017/12/22.
//

#include <iostream>
#include "game.h"
#include <cmath>

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

}

int Game::loop(){
    while(true){
        char fpsStr[100];
        sprintf(fpsStr, "%d", this->fps.fps());
        this->messageArea.message(fpsStr);
        if(this->nextScene){
            this->scene->endScene();
            this->scene = this->nextScene;
            this->scene->startScene();
            this->nextScene.reset();
        }
        if(this->scene) {
            this->scene->endScene();
            this->scene = scene;
            this->scene->startScene();
        }
        this->screen.swap();
        this->fps.wait();
    }
    return 0;
}

void Game::changeScene(std::shared_ptr<Scene> scene) {
    this->nextScene = scene;
}

