//
// Created by nakajimakotaro on 2018/01/03.
//

#include "collision.h"


void Collision::addObjectRequire(std::shared_ptr<Collider> obj) {
    this->addQueue.push_back(obj);
}
void Collision::removeObjectRequire(std::shared_ptr<Collider> obj) {
    this->removeQueue.push_back(obj);
}

void Collision::ququeExe(){
    auto removeResult = std::remove_if(this->collisionList.begin(), this->collisionList.end(), [this](auto obj){
        return std::find(this->removeQueue.begin(), this->removeQueue.end(), obj) != this->removeQueue.end();
    });
    this->collisionList.erase(removeResult, this->collisionList.end());
    this->removeQueue.clear();

    for(auto add: this->addQueue){
        this->collisionList.push_back(add);
    }
    this->addQueue.clear();
}
Rect intersect(const Rect& a, const Rect& b){
    Rect result;
    result.x = std::fmax(a.x, b.x);
    result.y = std::fmax(a.y, b.y);
    result.w = std::fmin(a.x + a.w, b.x + b.w) - result.x;
    result.h = std::fmin(a.y + a.h, b.y + b.h) - result.y;
    return result;
}
Rect intersect(std::shared_ptr<Collider> a, std::shared_ptr<Collider> b){
    return intersect(Rect(a->x(), a->y(), a->w, a->h),
                     Rect(b->x(), b->y(), b->w, b->h));
}

void Collision::tick() {
    this->ququeExe();
    for(auto ia = this->collisionList.begin();ia != this->collisionList.end();ia++){
        for(auto ib = ia + 1;ib != this->collisionList.end();ib++){
            auto& a = *ia;
            auto& b = *ib;
            Rect overlap = intersect(a, b);
            if(overlap.w <= 0 || overlap.h <= 0){
                continue;
            }
            a->collision(b, overlap);
            b->collision(a, overlap);
        }
    }
}

