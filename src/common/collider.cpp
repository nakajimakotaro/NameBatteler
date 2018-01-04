//
// Created by nakajimakotaro on 2018/01/04.
//

#include "collider.h"

Collider::Collider(std::weak_ptr<GameObject> parent, double localX, double localY, double w, double h,
                   std::function<void(std::shared_ptr<Collider>, Rect)> collision):
        GameObject(parent, localX, localY),
        w(w),
        h(h),
        collision(collision)
{
}
