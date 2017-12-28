//
// Created by harus on 2017/12/20.
//

#ifndef NAMEBATTLER_SCREEN_H
#define NAMEBATTLER_SCREEN_H

#include <windows.h>
#include "../common/rect.h"

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

class Screen {
private:
    static const int WIDTH = 160;
    static const int HEIGHT = 50;
private:
    std::vector<HANDLE> poolScreen = {};
    int frontScreenNumber = 0;
    Depth depth;
    Rect rect;


    HANDLE frontScreen();
    HANDLE backScreen();
public:
    Screen();
    void swap();
    void writeString(const char* str, int x, int y, int layer = 0, Rect rect = Rect(0, 0, Screen::WIDTH, Screen::HEIGHT));
    void writeChar(char c, int x, int y, int layer = 0);
    ~Screen();
};


#endif //NAMEBATTLER_SCREEN_H
