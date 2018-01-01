//
// Created by harus on 2017/12/22.
//

#ifndef NAMEBATTLER_GAME_H
#define NAMEBATTLER_GAME_H


#include <memory>
#include "screen.h"
#include "../scene/scene.h"
#include "fps.h"
#include "../scene/gameing/gameingScene.h"

class Game {
private:
    static std::unique_ptr<Game> instance;
    Game();
public:
    static std::unique_ptr<Game>& get();
private:
    std::shared_ptr<GameingScene> nextScene;
public:
    Screen screen;
    FPS fps;
    std::shared_ptr<GameingScene> scene;
    bool isExitRequire = false;

    int loop();
    void exitRequire();
    void changeScene(std::shared_ptr<GameingScene> scene);
};


#endif //NAMEBATTLER_GAME_H
