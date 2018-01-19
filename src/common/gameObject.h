//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_GAMEOBJECT_H
#define NAMEBATTLER_GAMEOBJECT_H


#include <memory>
#include <algorithm>
#include <vector>

class GameingScene;
class Scene;
class GameObject: public std::enable_shared_from_this<GameObject>{
public:
    enum class Type{
        PLAYER,
        CAMERA,
        BLOCK,
        MESSAGE_AREA,
        DEBUG_MESSAGE,
        COLLIDER,
        ENEMY,
        Layer,
        Particle,
        MoveParticle,
        DotBullet,
        WhipBullet,
        ArrowBullet,
        NameInput
    };
private:
    std::weak_ptr<GameObject> parent;
    std::vector<std::weak_ptr<GameObject>> childList;
    int startFrame;
public:
    double localX;
    double localY;
protected:
    GameObject(std::weak_ptr<Scene> scene, double localX, double localY);
public:
    std::weak_ptr<Scene> scene;
    std::weak_ptr<GameObject> getParent(){
        return this->parent;
    }
    double x() const;
    double y() const;
    void addChild(std::weak_ptr<GameObject> child);
    void removeChild(std::weak_ptr<GameObject> child);
    int countFrame();
    virtual void start(){};
    virtual void update(){};
    virtual void postUpdate(){};
    virtual void draw(){};
    virtual void end(){};
    virtual Type getType() = 0;
    virtual ~GameObject() = default;
};

#endif //NAMEBATTLER_GAMEOBJECT_H
