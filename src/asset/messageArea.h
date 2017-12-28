//
// Created by harus on 2017/12/23.
//

#ifndef NAMEBATTLER_MESSAGEBOX_H
#define NAMEBATTLER_MESSAGEBOX_H


#include "../common/rect.h"
#include "gameObject.h"

//80Byteまでのメッセージ(Shift-jisだから40字)
class MessageArea final: public GameObject{
public:
    MessageArea();
    void update() override;
    void draw() override;
    Type getType() override;

    Rect rect;

    void message(const char* str);
};


#endif //NAMEBATTLER_MESSAGEBOX_H
