//
// Created by harus on 2018/01/08.
//

#include "gameObject.h"

double GameObject::x() const {
    if(this->parent.use_count() != 0){
        return this->parent.lock()->x() + this->localX;
    }else{
        return this->localX;
    }
}

double GameObject::y() const {
    if(this->parent.use_count() != 0){
        return this->parent.lock()->y() + this->localY;
    }else{
        return this->localY;
    }
}

void GameObject::addChild(std::weak_ptr<GameObject> child) {
    this->childList.push_back(child);
    child.lock()->parent = shared_from_this();
}

void GameObject::removeChild(std::weak_ptr<GameObject> child) {
    auto index = std::distance(this->childList.begin(), std::find_if(this->childList.begin(), this->childList.end(), [child](auto a){
        return a.lock() == child.lock();
    }));
    this->childList[index] = *(this->childList.end() - 1);
    this->childList.pop_back();
}

GameObject::GameObject(double localX, double localY):
    localX(localX),
    localY(localY)
{
}


