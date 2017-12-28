//
// Created by harus on 2017/12/23.
//

#ifndef NAMEBATTLER_MESSAGEBOX_H
#define NAMEBATTLER_MESSAGEBOX_H


#include "../common/rect.h"

//80Byteまでのメッセージ(Shift-jisだから40字)
class MessageArea {
public:
    MessageArea();

    Rect rect;

    void message(const char* str);
};


#endif //NAMEBATTLER_MESSAGEBOX_H
