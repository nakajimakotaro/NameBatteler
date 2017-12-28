//
// Created by harus on 2017/12/23.
//

#ifndef NAMEBATTLER_RECT_H
#define NAMEBATTLER_RECT_H


class Rect {
public:
    explicit Rect(int x = 0, int y = 0, int w = 0, int h = 0);

    int x, y, w, h;
    bool in(int x, int y)const;
    Rect intersect(int x, int y, int w, int h)const;
    Rect intersect(const Rect& rect)const;
};


#endif //NAMEBATTLER_RECT_H

