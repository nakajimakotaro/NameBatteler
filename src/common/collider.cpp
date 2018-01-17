//
// Created by nakajimakotaro on 2018/01/04.
//

#include "collider.h"
#include "../core/game.h"

Collider::Collider(std::weak_ptr<GameingScene> scene, double localX, double localY, double w, double h,
                   std::function<void(std::shared_ptr<Collider>, Rect)> collision):
        GameObject(scene, localX, localY),
        w(w),
        h(h),
        collision(collision)
{
}
