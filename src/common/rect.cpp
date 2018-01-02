//
// Created by harus on 2017/12/23.
//

#include "rect.h"
#include <cmath>

Rect::Rect(double x, double y, double w, double h):
        x(x),
        y(y),
        w(w),
        h(h)
{
}

bool Rect::in(double x, double y)const{
    return x >= this->x &&
           x <  this->x + this->w &&
           y >= this->y &&
           y <  this->y + this->h;
}
Rect Rect::intersect(double x, double y, double w, double h) const {
    return this->intersect(Rect(x, y, w, h));
}
Rect Rect::intersect(const Rect& rect)const{
    Rect result;
    result.x = static_cast<double>(std::fmax(this->x, rect.x));
    result.y = static_cast<double>(std::fmax(this->y, rect.y));
    result.w = static_cast<double>(std::fmin(this->x + this->w, rect.x + rect.w) - result.x);
    result.h = static_cast<double>(std::fmin(this->y + this->h, rect.y + rect.h) - result.y);
    return result;
}
