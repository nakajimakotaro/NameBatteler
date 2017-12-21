#include <windows.h>
#include <vector>

#include "screen.h"

Screen::Screen(){
    this->poolScreen.push_back(CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr));
    this->poolScreen.push_back(CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr));
    SetConsoleActiveScreenBuffer(this->frontScreen());
}
HANDLE Screen::frontScreen(){
    return this->poolScreen[this->frontScreenNumber];
}
HANDLE Screen::backScreen(){
    int backScreenNumber = this->frontScreenNumber == 0 ? 1 : 0;
    return this->poolScreen[backScreenNumber];
}
void Screen::swapScreen(){
    this->frontScreenNumber = this->frontScreenNumber == 0 ? 1 : 0;
    SetConsoleActiveScreenBuffer(this->frontScreen());

    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo = {};
    GetConsoleScreenBufferInfo(this->backScreen(), &screenBufferInfo);

    COORD start = {0, 0};
    DWORD p;
    FillConsoleOutputCharacter(
            this->backScreen(),
            ' ',
            screenBufferInfo.dwSize.X * screenBufferInfo.dwSize.Y,
            {0, 0},
            &p
    );
}
void Screen::writeString(const char* str, int x, int y){
    DWORD p;
    WriteConsoleOutputCharacter(this->backScreen(), str, strlen(str), {x, y}, &p);
}

Screen::~Screen(){
    for(auto h = this->poolScreen.begin();h != this->poolScreen.end();h++) {
        CloseHandle(*h);
    }
}
