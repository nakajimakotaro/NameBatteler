//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_FPS_H
#define NAMEBATTLER_FPS_H


#include <vector>

class FPS {
public:
    explicit FPS(int fps);
    double interval;
    int startFrameTime = 0;
    std::vector<int> realIntervalList;
    int intervalLast = 0;
    void wait();
    int fps();
};


#endif //NAMEBATTLER_FPS_H
