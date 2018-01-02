//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_GAMEINGSCENE_H
#define NAMEBATTLER_GAMEINGSCENE_H


#include <vector>
#include <memory>
#include "../scene.h"
#include "../../asset/gameObject.h"
#include "gameingInputManager.h"
#include <algorithm>

class GameingScene final: public Scene{
private:
    std::vector<std::shared_ptr<GameObject>> addQueueList;
public:
    GameingInputManager inputManager;
public:
    GameingScene();
    std::vector<std::shared_ptr<GameObject>> objectList;
    void startScene() override;
    void update() override;
    void draw() override;
    void endScene() override;
    void addObject(std::shared_ptr<GameObject> obj);
    template <typename T> std::shared_ptr<T> getObject(GameObject::Type type);
    template <typename T> std::vector<std::shared_ptr<T>> getObjectAll(GameObject::Type type);
};

template <typename T>
std::shared_ptr<T> GameingScene::getObject(GameObject::Type type){
    return std::dynamic_pointer_cast<T>(*std::find_if(this->objectList.begin(), this->objectList.end(),
                         [type](auto obj){
                             return obj->getType() == type;
                         }));
}
template <typename T>
std::vector<std::shared_ptr<T>> GameingScene::getObjectAll(GameObject::Type type){
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


#endif //NAMEBATTLER_GAMEINGSCENE_H
