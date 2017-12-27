#include <windows.h>
#include <vector>

#include "screen.h"

Screen::Screen():
rect(0, 0, Screen::WIDTH, Screen::HEIGHT),
depth(Screen::WIDTH, Screen::HEIGHT)
{
    for(int i = 0;i < 2;i++){
        HANDLE handle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
        this->poolScreen.push_back(handle);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(handle, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(handle, &cursorInfo);
    }
    this->swap(); //Å‰‚Ì‰æ–Ê‚Í‰Šú‰»‚³‚ê‚Ä‚¢‚È‚¢‚Ì‚Åˆê“xswap‚µ‚Ä‚¨‚­
}
HANDLE Screen::frontScreen(){
    return this->poolScreen[this->frontScreenNumber];
}
HANDLE Screen::backScreen(){
    int backScreenNumber = this->frontScreenNumber == 0 ? 1 : 0;
    return this->poolScreen[backScreenNumber];
}
void Screen::swap(){
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

    this->depth.clean();
}

Screen::~Screen(){
    for(auto h = this->poolScreen.begin();h != this->poolScreen.end();h++) {
        CloseHandle(*h);
    }
}

void Screen::writeString(const char* text, int x, int y,  int layer, Rect rect){
    const size_t len = strlen(text);
    Rect drawRect = rect.intersect(x, y, len, 1);
    if(drawRect.w < 0 || drawRect.h < 0){
        return;
    }
    for(int i = 0;i < drawRect.w;i++){
        this->writeChar(text[i], drawRect.x + i, y, layer);
    }
}
void Screen::writeChar(char c, int x, int y, int layer){
    if(
            !this->rect.in(x, y) ||
            !this->depth.checkFront(x, y, layer)) {
        return;
    }
    char cStr[2] = {c, '\0'};
    DWORD p;
    WriteConsoleOutputCharacter(this->backScreen(), cStr, 1, {(SHORT)x, (SHORT)y}, &p);
    this->depth.write(x, y, layer);
}

