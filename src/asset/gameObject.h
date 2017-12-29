//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_GAMEOBJECT_H
#define NAMEBATTLER_GAMEOBJECT_H


class GameObject {
public:
    enum class Type{
        PLAYER
    };
    virtual void update(){};
    virtual void draw(){};
    virtual Type getType() = 0;
    virtual ~GameObject() = default;
};


#endif //NAMEBATTLER_GAMEOBJECT_H
