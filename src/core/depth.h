//
// Created by harus on 2017/12/22.
//

#ifndef NAMEBATTLER_DEPTH_H
#define NAMEBATTLER_DEPTH_H


#include <vector>

class Depth {
private:
    std::vector<int> depthLayer;
    const int width, height;
public:
    Depth(int w, int h);
    bool checkFront(int x, int y, int layer);
    void write(int x, int y, int layer);
    void clean();
};


#endif //NAMEBATTLER_DEPTH_H
