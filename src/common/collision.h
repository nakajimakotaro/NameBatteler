//
// Created by nakajimakotaro on 2018/01/03.
//

#ifndef NAMEBATTLER_COLLISION_H
#define NAMEBATTLER_COLLISION_H


#include <memory>
#include <vector>
#include "rect.h"
#include "collider.h"
//当たり判定の管理
class Collision {
private:
    std::vector<std::shared_ptr<Collider>> collisionList;
    std::vector<std::shared_ptr<Collider>> addQueue;
    std::vector<std::shared_ptr<Collider>> removeQueue;
public:
    Collision() = default;
    //当たり判定を取るオブジェクトの追加
    void addObjectRequire(std::shared_ptr<Collider> obj);
    //当たり判定を取るオブジェクトの削除
    void removeObjectRequire(std::shared_ptr<Collider> obj);
    //当たり判定を取ってコールバックを呼び出す
    void tick();
private:
    void ququeExe();
};


#endif //NAMEBATTLER_COLLISION_H
