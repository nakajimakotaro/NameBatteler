//
// Created by harus on 2017/12/29.
//

#include "inputManager.h"
#include <windows.h>

bool InputManager::isPush(LIST key) {
    return (GetAsyncKeyState(static_cast<int>(key)) & 1 << 15) != 0;
}

void InputManager::update() {
}
