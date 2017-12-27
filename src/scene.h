//
// Created by harus on 2017/12/27.
//

#ifndef NAMEBATTLER_SCENE_H
#define NAMEBATTLER_SCENE_H


class Scene {
private:
public:
    virtual void startScene() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void endScene() = 0;
    virtual ~Scene();
};


#endif //NAMEBATTLER_SCENE_H
