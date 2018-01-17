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
class GameingScene final: public Scene, public std::enable_shared_from_this<GameingScene>{
private:
    bool isPause = false;
public:
    std::unique_ptr<GameingInputManager> inputManager;
    Collision collision;
public:
    GameingScene();
    void startScene() override;
    void update() override;
    void draw() override;
    void endScene() override;

    void pause();
    void reset();
};

#endif //NAMEBATTLER_GAMEINGSCENE_H
