//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_GAMEINGSCENE_H
#define NAMEBATTLER_GAMEINGSCENE_H


#include <vector>
#include <memory>
#include "../scene.h"
#include "../../common/collision.h"

class GameingInputManager;
class GameingScene final: public Scene{
private:
    bool isPause = false;
    std::string name;
    std::string mapPath;
public:
    std::unique_ptr<GameingInputManager> inputManager;
public:
    GameingScene(std::string name, std::string mapPath);
    void startScene() override;
    void update() override;
    void draw() override;
    void endScene() override;

    void pause();
    void reset() override ;
    void goal();

private:
    void load();
};

#endif //NAMEBATTLER_GAMEINGSCENE_H
