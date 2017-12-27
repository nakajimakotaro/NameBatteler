//
// Created by harus on 2017/12/22.
//

#ifndef NAMEBATTLER_GAME_H
#define NAMEBATTLER_GAME_H


#include <vector>
#include <memory>
#include "screen.h"
#include "commandManager.h"
#include "messageArea.h"
#include "scene.h"
#include "fps.h"

class Game {
private:
    static std::unique_ptr<Game> instance;
    Game();
public:
    static std::unique_ptr<Game>& get();
private:
    std::shared_ptr<Scene> nextScene;
public:
    Screen screen;
    std::shared_ptr<Scene> scene;
    MessageArea messageArea;
    FPS fps;

    int loop();
    void changeScene(std::shared_ptr<Scene> scene);
};


#endif //NAMEBATTLER_GAME_H
