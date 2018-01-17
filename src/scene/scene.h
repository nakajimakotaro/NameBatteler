//
// Created by harus on 2017/12/27.
//

#ifndef NAMEBATTLER_SCENE_H
#define NAMEBATTLER_SCENE_H

#include <memory>
#include <vector>
#include <algorithm>
#include "../common/gameObject.h"

class Scene {
protected:
    std::vector<std::shared_ptr<GameObject>> addQueueList{};
    std::vector<std::shared_ptr<GameObject>> removeQueueList{};
    std::vector<std::shared_ptr<GameObject>> objectList;
    void queueUpdate();
public:
    virtual void startScene(){};
    virtual void update(){};
    virtual void draw(){};
    virtual void endScene(){};
    std::shared_ptr<GameObject> addObject(std::weak_ptr<GameObject> obj);;
    std::shared_ptr<GameObject> removeObject(std::weak_ptr<GameObject> obj);;
    template <typename T> std::shared_ptr<T> getObject(GameObject::Type type);
    template <typename T> std::vector<std::shared_ptr<T>> getObjectAll(GameObject::Type type);
    virtual ~Scene() = default;
};

template <typename T>
std::shared_ptr<T> Scene::getObject(GameObject::Type type){
    return std::dynamic_pointer_cast<T>(*std::find_if(this->objectList.begin(), this->objectList.end(),
                         [type](auto obj){
                             return obj->getType() == type;
                         }));
}
template <typename T>
std::vector<std::shared_ptr<T>> Scene::getObjectAll(GameObject::Type type){
    std::vector<std::shared_ptr<T>> res;
    auto begin = this->objectList.begin();
    while (true) {
        begin = std::find_if(begin, this->objectList.end(),
                             [type](auto obj) {
                                 return obj->getType() == type;
                             });
        if (begin != this->objectList.end()) {
            res.push_back(std::dynamic_pointer_cast<T>(*begin));
            begin++;
        } else {
            break;
        }
    }
    return res;
}


class NoneScene: public Scene{
};

#endif //NAMEBATTLER_SCENE_H
