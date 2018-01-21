//
// Created by harus on 2018/01/18.
//

#ifndef NAMEBATTLER_NAMEINPUT_H
#define NAMEBATTLER_NAMEINPUT_H


#include "../common/gameObject.h"

class NameInput: public GameObject {
public:
    std::string name = "";
    NameInput(std::weak_ptr<Scene> scene, double x, double y);
    void update() override;
    void draw() override;
    void end() override;
    GameObject::Type getType(){
        return GameObject::Type::NameInput;
    }
};


#endif //NAMEBATTLER_NAMEINPUT_H
