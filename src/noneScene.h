//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_NONESCENE_H
#define NAMEBATTLER_NONESCENE_H


#include "scene.h"

//�������Ȃ��V�[��
class NoneScene final : public Scene{
public:
    void startScene() override;
    void update() override;
    void draw() override;
    void endScene() override;
};


#endif //NAMEBATTLER_NONESCENE_H
