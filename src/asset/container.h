//
// Created by harus on 2018/01/07.
//

#ifndef NAMEBATTLER_CONTAINER_H
#define NAMEBATTLER_CONTAINER_H


#include "../common/gameObject.h"

class Container: GameObject{
private:
    Container();
public:
    GameObject::Type getType() override;
};


#endif //NAMEBATTLER_CONTAINER_H
