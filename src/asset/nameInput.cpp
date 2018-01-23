//
// Created by harus on 2018/01/18.
//

#include "nameInput.h"
#include "../core/game.h"
#include "../scene/gameing/gameingInputManager.h"
#include "../scene/gameing/gameingScene.h"

NameInput::NameInput(std::weak_ptr<Scene> scene, double x, double y) : GameObject(scene, x, y) {
}


int prevTime = 0;
void NameInput::update() {
    if(this->scene.lock()->input.isPush(InputManager::LIST::KEY_BACK)){
        if(prevTime + 180 < timeGetTime() && !this->name.empty()) {
            prevTime = timeGetTime();
            this->name.pop_back();
        }
    }
    for(auto key: this->scene.lock()->input.pushKey()){
        if(prevTime + 180 < timeGetTime()){
            char keyChara = this->scene.lock()->input.toChar(key);
            if(keyChara != 0){
                prevTime = timeGetTime();
                this->name.push_back(keyChara);
                break;
            }
        }
    }
    if(this->scene.lock()->input.isPush(InputManager::LIST::KEY_RETURN)){
        Game::get()->changeScene(std::make_shared<GameingScene>(this->name, "map/map.json"));
    }
}

void NameInput::draw() {
    Game::get()->screen.writeString("your name?", this->x() - 4, this->y() - 7);

    if(this->countFrame() < 30){
        for(int i=-50;i <= 50;i++){
            Game::get()->screen.writeChar('-', this->x() + (double)i * this->countFrame() / 30, this->y());
        }
    }else{
        for(int i=-50;i <= 50;i++){
            Game::get()->screen.writeChar('-', this->x() + i, this->y() - 1);
            Game::get()->screen.writeChar('-', this->x() + i, this->y() + 1);
        }
        Game::get()->screen.writeChar('|', this->x() - 50, this->y());
        Game::get()->screen.writeChar('|', this->x() + 50, this->y());

        Game::get()->screen.writeString(this->name, this->x() - 49, this->y());
        Game::get()->screen.cursorShow(this->x() - 49 + this->name.length(), this->y());
    }
}

void NameInput::end() {
    Game::get()->screen.cursorHide();
}

