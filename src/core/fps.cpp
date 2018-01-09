//
// Created by harus on 2017/12/28.
//

#include "fps.h"
#include <windows.h>
#include <cfloat>
#include <cmath>
#include <numeric>

FPS::FPS(int fps):
        interval(1000.0 / fps),
        realIntervalList(fps)
{
}



void FPS::wait() {
    const int now = timeGetTime();
    const int useTime = now - this->startFrameTime;
    int sleepTime = this->interval - useTime;
    if(sleepTime < 2){
        sleepTime = 2;
    }

    const int prevStartTime = this->startFrameTime;
    Sleep(sleepTime);

    this->startFrameTime = timeGetTime();

    this->realIntervalList[this->intervalLast] = this->startFrameTime - prevStartTime;
    this->intervalLast++;
    if(this->intervalLast >= this->realIntervalList.size()){
        this->intervalLast = 0;
    }
    this->countFrame++;
}

int FPS::fps() {
    double average = std::accumulate(this->realIntervalList.begin(), this->realIntervalList.end(), 0) / this->realIntervalList.size();
    if(average == 0){
        return 0;
    }
    return static_cast<int>(round(1000 / average));
}

int FPS::getCountFrame() {
    return this->countFrame;
}

