//
// Created by harus on 2018/01/08.
//

#include "gameObject.h"
#include "../core/game.h"

GameObject::GameObject(std::weak_ptr<Scene> scene, double localX, double localY):
        scene(scene),
        localX(localX),
        localY(localY),
        startFrame(Game::get()->fps.getCountFrame())
{
}
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
    if(this->childList.size() >= index){
        return;
    }
    this->childList[index] = *(this->childList.end() - 1);
    this->childList.pop_back();
}

int GameObject::countFrame() {
    return Game::get()->fps.getCountFrame() - this->startFrame;
}

