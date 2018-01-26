//
// Created by nakajimakotaro on 2018/01/26.
//

#ifndef NAMEBATTLER_ENDSCENE_H
#define NAMEBATTLER_ENDSCENE_H


#include "../scene.h"

class EndScene: public Scene {
    std::string name;
public:
    EndScene(std::string name);
    void startScene() override ;
    void update() override ;
    void draw() override ;
};


#endif //NAMEBATTLER_ENDSCENE_H
