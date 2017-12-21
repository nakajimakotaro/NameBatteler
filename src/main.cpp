#include <windows.h>
#include <c++/vector>
#include "screen.h"

int main() {
    int i = 0;
    Screen screen;
    while(true){
        i++;
        screen.writeString("hello, ll‚Í‚ë‚¤‚¦", 0, 0);
        screen.writeString("hello, l0xlllllll", 0, 1);
        screen.swapScreen();
        Sleep(1000 / 30);
        if(i == 99999999){
            break;
        }
    }
    return 0;
}
