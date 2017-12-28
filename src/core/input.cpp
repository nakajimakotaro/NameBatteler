//
// Created by harus on 2017/12/22.
//

#include "input.h"
#include <windows.h>

bool Input::isPush(int key) {
    return GetAsyncKeyState(key) != 0;
}

