//
// Created by nakajimakotaro on 2018/01/03.
//

#ifndef NAMEBATTLER_COLLISION_H
#define NAMEBATTLER_COLLISION_H


#include <memory>
#include <vector>
#include "rect.h"
#include "collider.h"
//�����蔻��̊Ǘ�
class Collision {
private:
    std::vector<std::shared_ptr<Collider>> collisionList;
    std::vector<std::shared_ptr<Collider>> addQueue;
    std::vector<std::shared_ptr<Collider>> removeQueue;
public:
    Collision() = default;
    //�����蔻������I�u�W�F�N�g�̒ǉ�
    void addObjectRequire(std::shared_ptr<Collider> obj);
    //�����蔻������I�u�W�F�N�g�̍폜
    void removeObjectRequire(std::shared_ptr<Collider> obj);
    //�����蔻�������ăR�[���o�b�N���Ăяo��
    void tick();
private:
    void ququeExe();
};


#endif //NAMEBATTLER_COLLISION_H
