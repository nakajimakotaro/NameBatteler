//
// Created by harus on 2017/12/29.
//

#include "inputManager.h"
#include <windows.h>
#include <vector>

bool InputManager::isPush(LIST key) {
    return (GetAsyncKeyState(static_cast<int>(key)) & 1 << 15) != 0;
}
//現在押されているキーを返す
std::vector<InputManager::LIST> InputManager::pushKey() {
    std::vector<InputManager::LIST> inputList;
    for(auto key = LIST::KEY_0;key <= LIST::KEY_Z; key = static_cast<LIST>(static_cast<int>(key) + 1)){
        if(this->isPush(key)){
            inputList.push_back(key);
        }
    }
    return inputList;
}

//押されたキーを文字に変換する
char InputManager::toChar(InputManager::LIST key){
    char chara;
    switch(key){
        case InputManager::LIST::KEY_SPACE:chara = ' ';break;
        case InputManager::LIST::KEY_0:chara = '0';break;
        case InputManager::LIST::KEY_1:chara = '1';break;
        case InputManager::LIST::KEY_2:chara = '2';break;
        case InputManager::LIST::KEY_3:chara = '3';break;
        case InputManager::LIST::KEY_4:chara = '4';break;
        case InputManager::LIST::KEY_5:chara = '5';break;
        case InputManager::LIST::KEY_6:chara = '6';break;
        case InputManager::LIST::KEY_7:chara = '7';break;
        case InputManager::LIST::KEY_8:chara = '8';break;
        case InputManager::LIST::KEY_9:chara = '9';break;
        case InputManager::LIST::KEY_A:chara = 'A';break;
        case InputManager::LIST::KEY_B:chara = 'B';break;
        case InputManager::LIST::KEY_C:chara = 'C';break;
        case InputManager::LIST::KEY_D:chara = 'D';break;
        case InputManager::LIST::KEY_E:chara = 'E';break;
        case InputManager::LIST::KEY_F:chara = 'F';break;
        case InputManager::LIST::KEY_G:chara = 'G';break;
        case InputManager::LIST::KEY_H:chara = 'H';break;
        case InputManager::LIST::KEY_I:chara = 'I';break;
        case InputManager::LIST::KEY_J:chara = 'J';break;
        case InputManager::LIST::KEY_K:chara = 'K';break;
        case InputManager::LIST::KEY_L:chara = 'L';break;
        case InputManager::LIST::KEY_M:chara = 'M';break;
        case InputManager::LIST::KEY_N:chara = 'N';break;
        case InputManager::LIST::KEY_O:chara = 'O';break;
        case InputManager::LIST::KEY_P:chara = 'P';break;
        case InputManager::LIST::KEY_Q:chara = 'Q';break;
        case InputManager::LIST::KEY_R:chara = 'R';break;
        case InputManager::LIST::KEY_S:chara = 'S';break;
        case InputManager::LIST::KEY_T:chara = 'T';break;
        case InputManager::LIST::KEY_U:chara = 'U';break;
        case InputManager::LIST::KEY_V:chara = 'V';break;
        case InputManager::LIST::KEY_W:chara = 'W';break;
        case InputManager::LIST::KEY_X:chara = 'X';break;
        case InputManager::LIST::KEY_Y:chara = 'Y';break;
        case InputManager::LIST::KEY_Z:chara = 'Z';break;
        default:
            chara = 0;
            break;
    }
    return chara;
}

void InputManager::update() {
}
