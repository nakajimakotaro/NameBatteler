//
// Created by harus on 2017/12/29.
//

#ifndef NAMEBATTLER_INPUTMANAGER_H
#define NAMEBATTLER_INPUTMANAGER_H


#include <vector>

class InputManager {
public:
    enum class LIST{
        KEY_LBUTTON = 0x01,
        KEY_RBUTTON = 0x02,
        KEY_CANCEL = 0x03,
        KEY_MBUTTON = 0x04,
        KEY_XBUTTON1 = 0x05,
        KEY_XBUTTON2 = 0x06,
        KEY_BACK = 0x08,
        KEY_TAB = 0x09,
        KEY_CLEAR = 0x0C,
        KEY_RETURN = 0x0D,
        KEY_SHIFT = 0x10,
        KEY_CONTROL = 0x11,
        KEY_MENU = 0x12,
        KEY_PAUSE = 0x13,
        KEY_CAPITAL = 0x14,
        KEY_KANA = 0x15,
        KEY_HANGUEL = 0x15,
        KEY_HANGUL = 0x15,
        KEY_JUNJA = 0x17,
        KEY_FINAL = 0x18,
        KEY_HANJA = 0x19,
        KEY_KANJI = 0x19,
        KEY_ESCAPE = 0x1B,
        KEY_CONVERT = 0x1C,
        KEY_NONCONVERT = 0x1D,
        KEY_ACCEPT = 0x1E,
        KEY_MODECHANGE = 0x1F,
        KEY_SPACE = 0x20,
        KEY_PRIOR = 0x21,
        KEY_NEXT = 0x22,
        KEY_END = 0x23,
        KEY_HOME = 0x24,
        KEY_LEFT = 0x25,
        KEY_UP = 0x26,
        KEY_RIGHT = 0x27,
        KEY_DOWN = 0x28,
        KEY_SELECT = 0x29,
        KEY_PRINT = 0x2A,
        KEY_SNAPSHOT = 0x2C,
        KEY_INSERT = 0x2D,
        KEY_DELETE = 0x2E,
        KEY_HELP = 0x2F,
        KEY_0 = 0x30,
        KEY_1 = 0x31,
        KEY_2 = 0x32,
        KEY_3 = 0x33,
        KEY_4 = 0x34,
        KEY_5 = 0x35,
        KEY_6 = 0x36,
        KEY_7 = 0x37,
        KEY_8 = 0x38,
        KEY_9 = 0x39,
        KEY_A = 0x41,
        KEY_B = 0x42,
        KEY_C = 0x43,
        KEY_D = 0x44,
        KEY_E = 0x45,
        KEY_F = 0x46,
        KEY_G = 0x47,
        KEY_H = 0x48,
        KEY_I = 0x49,
        KEY_J = 0x4A,
        KEY_K = 0x4B,
        KEY_L = 0x4C,
        KEY_M = 0x4D,
        KEY_N = 0x4E,
        KEY_O = 0x4F,
        KEY_P = 0x50,
        KEY_Q = 0x51,
        KEY_R = 0x52,
        KEY_S = 0x53,
        KEY_T = 0x54,
        KEY_U = 0x55,
        KEY_V = 0x56,
        KEY_W = 0x57,
        KEY_X = 0x58,
        KEY_Y = 0x59,
        KEY_Z = 0x5A,
    };
public:
    virtual ~InputManager() = default;
    bool isPush(LIST key);
    virtual void update();

    std::vector<LIST> pushKey();

    char toChar(LIST key);
};


#endif //NAMEBATTLER_INPUTMANAGER_H
