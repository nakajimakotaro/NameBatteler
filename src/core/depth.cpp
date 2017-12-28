//
// Created by harus on 2017/12/22.
//

#include <climits>
#include "depth.h"
Depth::Depth(int w, int h):
        width(w),
        height(h),
        depthLayer(w * h, INT_MIN)
{
}

bool Depth::checkFront(int x, int y, int layer){
    return this->depthLayer[x + y * this->width] <= layer;
}
void Depth::write(int x, int y, int layer){
    if(this->checkFront(x, y, layer)){
        this->depthLayer[x + y * this->width] = layer;
    }
}
void Depth::clean(){
    std::fill(this->depthLayer.begin(), this->depthLayer.end(), INT_MIN);
}

