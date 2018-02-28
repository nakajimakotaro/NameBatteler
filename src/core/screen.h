//
// Created by harus on 2017/12/20.
//

#ifndef NAMEBATTLER_SCREEN_H
#define NAMEBATTLER_SCREEN_H

#include <windows.h>
#include <vector>
#include "../common/rect.h"

struct Layer{
    int depth = 0;

};
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
public:
    enum class ForColor{
        RED = FOREGROUND_RED,
        BLUE = FOREGROUND_BLUE,
        GREEN = FOREGROUND_GREEN,
        CYAN = BLUE | GREEN,
        MAGENTA = RED | BLUE,
        YELLOW = RED | GREEN,
        WHILE = RED | GREEN | BLUE,
        BLACK = 0,
    };
    enum class BackColor {
        RED = BACKGROUND_RED,
        BLUE = BACKGROUND_BLUE,
        GREEN = BACKGROUND_GREEN,
        CYAN = BLUE | GREEN,
        MAGENTA = RED | BLUE,
        YELLOW = RED | GREEN,
        WHILE = RED | GREEN | BLUE,
        BLACK = 0,
    };
    constexpr static const int WIDTH = 160;
    constexpr static const int HEIGHT = 50;
private:
    std::vector<HANDLE> poolScreen = {};
    int frontScreenNumber = 0;
    Depth depth;


    HANDLE frontScreen();
    HANDLE backScreen();
public:
    Rect rect;
    Screen();
    void swap();
    void writeString(std::string str,
                     double x,
                     double y,
                     ForColor forColor = ForColor::BLACK,
                     BackColor backColor = BackColor::WHILE,
                     int layer = 0,
                     Rect rect = Rect(-1, -1, -1, -1));
    void writeChar(char c,
                   double x,
                   double y,
                   ForColor forColor = ForColor::BLACK,
                   BackColor backColor = BackColor::WHILE,
                   int layer = 0);
    void move(int x, int y);
    void cursorShow(int x, int y);
    void cursorHide();
    ~Screen();
private: void writeZenkaku(char f, char l, double x, double y, Screen::ForColor forColor, Screen::BackColor backColor, int layer);
};


#endif //NAMEBATTLER_SCREEN_H
