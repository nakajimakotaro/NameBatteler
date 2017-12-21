//
// Created by harus on 2017/12/20.
//

#ifndef NAMEBATTLER_SCREEN_H
#define NAMEBATTLER_SCREEN_H


class Screen {
private:
    std::vector<HANDLE> poolScreen = {};
    int frontScreenNumber = 0;

    HANDLE frontScreen();
    HANDLE backScreen();
public:
    Screen();
    void swapScreen();
    void writeString(const char* str, int x, int y);
    ~Screen();
};


#endif //NAMEBATTLER_SCREEN_H
