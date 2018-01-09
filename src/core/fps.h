//
// Created by harus on 2017/12/28.
//

#ifndef NAMEBATTLER_FPS_H
#define NAMEBATTLER_FPS_H


#include <vector>

class FPS {
private:
    double interval;
    int startFrameTime = 0;
    std::vector<int> realIntervalList;
    int intervalLast = 0;
    int countFrame = 0;
public:
    explicit FPS(int fps);
    void wait();
    int fps();
    int getCountFrame();
};


#endif //NAMEBATTLER_FPS_H
