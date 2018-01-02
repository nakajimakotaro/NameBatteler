//
// Created by harus on 2017/12/23.
//

#ifndef NAMEBATTLER_RECT_H
#define NAMEBATTLER_RECT_H


class Rect {
public:
    explicit Rect(double x = 0, double y = 0, double w = 0, double h = 0);

    double x, y, w, h;
    bool in(double x, double y)const;
    Rect intersect(double x, double y, double w, double h)const;
    Rect intersect(const Rect& rect)const;
};


#endif //NAMEBATTLER_RECT_H

