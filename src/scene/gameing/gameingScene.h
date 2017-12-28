//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_GAMEINGSCENE_H
#define NAMEBATTLER_GAMEINGSCENE_H


#include <vector>
#include <memory>
#include "../scene.h"
#include "../../asset/gameObject.h"

class GameingScene final: public Scene{
public:
    GameingScene();
    std::vector<std::unique_ptr<GameObject>> objectList;
    void startScene() override;
    void update() override;
    void draw() override;
    void endScene() override;
};


#endif //NAMEBATTLER_GAMEINGSCENE_H
