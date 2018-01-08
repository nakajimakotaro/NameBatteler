#include <windows.h>
#include <vector>
#include <string>
#include <cmath>
#include "screen.h"

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


Screen::Screen():
        rect(0, 0, Screen::WIDTH, Screen::HEIGHT),
        depth(Screen::WIDTH, Screen::HEIGHT)
{
    for(int i = 0;i < 2;i++){
        HANDLE handle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(handle, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(handle, &cursorInfo);
        SetConsoleScreenBufferSize(handle, {Screen::WIDTH, Screen::HEIGHT});
        SMALL_RECT winRect{0, 0, Screen::WIDTH - 1, Screen::HEIGHT - 1};
        SetConsoleWindowInfo(handle, TRUE, &winRect);

        this->poolScreen.push_back(handle);
    }
    this->swap(); //最初の画面は初期化されていないので一度swapしておく
}
HANDLE Screen::frontScreen(){
    return this->poolScreen[this->frontScreenNumber];
}
HANDLE Screen::backScreen(){
    return this->poolScreen[this->frontScreenNumber == 0 ? 1 : 0];
}
void Screen::swap(){
    this->frontScreenNumber = this->frontScreenNumber == 0 ? 1 : 0;
    SetConsoleActiveScreenBuffer(this->frontScreen());

    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo = {};
    GetConsoleScreenBufferInfo(this->backScreen(), &screenBufferInfo);

    DWORD p;
    FillConsoleOutputAttribute(
            this->backScreen(),
            static_cast<int>(Screen::ForColor::WHILE),
            static_cast<DWORD>(screenBufferInfo.dwSize.X * screenBufferInfo.dwSize.Y),
            {0, 0},
            &p
    );
    FillConsoleOutputCharacter(
            this->backScreen(),
            ' ',
            static_cast<DWORD>(screenBufferInfo.dwSize.X * screenBufferInfo.dwSize.Y),
            {0, 0},
            &p
    );

    this->depth.clean();
}

Screen::~Screen(){
    for (auto &h : this->poolScreen) {
        CloseHandle(h);
    }
}

void Screen::writeString(std::string str,
                         double x,
                         double y,
                         ForColor forColor,
                         BackColor backColor,
                         int layer,
                         Rect rect){
    if(rect.w == -1 && rect.h == -1){
        rect = this->rect;
    }
    Rect drawRect = rect.intersect(x, y, str.length(), 1);
    if(drawRect.w < 0 || drawRect.h < 0){
        return;
    }
    for(int i = 0;i < drawRect.w;i++){
        this->writeChar(str[i], drawRect.x + i, y, forColor, backColor, layer);
    }
}
void Screen::writeChar(char c, double x, double y, Screen::ForColor forColor, Screen::BackColor backColor, int layer) {
    int screenX = std::floor(x - this->rect.x);
    int screenY = std::floor(y - this->rect.y);
    if(
            !this->rect.in(x, y) ||
            !this->depth.checkFront(screenX, screenY, layer)) {
        return;
    }
    DWORD p;
    WORD attribute = static_cast<int>(forColor) | static_cast<int>(backColor);
    WriteConsoleOutputAttribute(this->backScreen(), &attribute, 1, {(SHORT)screenX, (SHORT)screenY}, &p);
    WriteConsoleOutputCharacter(this->backScreen(), &c, 1, {(SHORT)screenX, (SHORT)screenY}, &p);
    this->depth.write(screenX, screenY, layer);
}

void Screen::move(int x, int y){
    this->rect.x = x;
    this->rect.y = y;
}
