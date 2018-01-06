//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_GAMEOBJECT_H
#define NAMEBATTLER_GAMEOBJECT_H


#include <memory>

class GameObject {
public:
    enum class Type{
        PLAYER,
        CAMERA,
        BLOCK,
        MESSAGE_AREA,
        DEBUG_MESSAGE,
        COLLIDER,
        ENEMY
    };

    GameObject(std::weak_ptr<GameObject> parent, double localX, double localY):
            parent(parent),
            localX(localX),
            localY(localY)
    { };
    std::weak_ptr<GameObject> parent;
    double localX;
    double localY;
    double x()const {
        if(this->parent.use_count() != 0){
            return this->parent.lock()->x() + this->localX;
        }else{
            return this->localX;
        }
    }
    double y() const{
        if(this->parent.use_count() != 0){
            return this->parent.lock()->y() + this->localY;
        }else{
            return this->localY;
        }
    }
    virtual void start(){};
    virtual void update(){};
    virtual void draw(){};
    virtual void end(){};
    virtual Type getType() = 0;
    virtual ~GameObject() = default;
};


#endif //NAMEBATTLER_GAMEOBJECT_H
