//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_GAMEINGSCENE_H
#define NAMEBATTLER_GAMEINGSCENE_H


#include <vector>
#include <memory>
#include <algorithm>
#include "../scene.h"
#include "../../common/gameObject.h"
#include "../../common/collision.h"

class GameingInputManager;
class GameingScene final: public Scene, public std::enable_shared_from_this<GameingScene>{
private:
    std::vector<std::shared_ptr<GameObject>> addQueueList{};
    std::vector<std::shared_ptr<GameObject>> removeQueueList{};
    void queueUpdate();
    bool isPause = false;
    bool resetRequire = false;
    std::vector<std::shared_ptr<GameObject>> objectList;
public:
    std::unique_ptr<GameingInputManager> inputManager;
    Collision collision;
public:
    GameingScene();
    void startScene() override;
    void update() override;
    void draw() override;
    void endScene() override;
    std::shared_ptr<GameObject> addObject(std::weak_ptr<GameObject> obj);
    std::shared_ptr<GameObject> removeObject(std::weak_ptr<GameObject> obj);
    template <typename T> std::shared_ptr<T> getObject(GameObject::Type type);
    template <typename T> std::vector<std::shared_ptr<T>> getObjectAll(GameObject::Type type);

    void pause();
    void reset();
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
