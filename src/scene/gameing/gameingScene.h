//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_GAMEINGSCENE_H
#define NAMEBATTLER_GAMEINGSCENE_H


#include <vector>
#include <memory>
#include "../scene.h"
#include "../../asset/gameObject.h"
#include "gameingInputManager.h"

class GameingScene final: public Scene{
private:
    std::vector<std::shared_ptr<GameObject>> addQueueList;
public:
    GameingInputManager inputManager;
public:
    GameingScene();
    std::vector<std::shared_ptr<GameObject>> objectList;
    void startScene() override;
    void update() override;
    void draw() override;
    void endScene() override;
    void addObject(std::shared_ptr<GameObject> obj);
};


#endif //NAMEBATTLER_GAMEINGSCENE_H
