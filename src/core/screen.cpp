#include <windows.h>
#include <vector>

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
    this->swap(); //Å‰‚Ì‰æ–Ê‚Í‰Šú‰»‚³‚ê‚Ä‚¢‚È‚¢‚Ì‚Åˆê“xswap‚µ‚Ä‚¨‚­
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
    WriteConsoleOutputCharacter(this->backScreen(), cStr, 1, {(SHORT)(x - this->rect.x), (SHORT)(y - this->rect.y)}, &p);
    this->depth.write(x, y, layer);
}

void Screen::move(int x, int y){
    this->rect.x = x;
    this->rect.y = y;
}

