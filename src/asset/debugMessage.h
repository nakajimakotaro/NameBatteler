//
// Created by nakajimakotaro on 2018/01/02.
//

#ifndef NAMEBATTLER_DEBUGMESSAGE_H
#define NAMEBATTLER_DEBUGMESSAGE_H


#include "gameObject.h"
#include "../common/rect.h"

class DebugMessage : public GameObject{
public:
    DebugMessage();
    void update() override;
    void draw() override;
    Type getType() override;

    Rect rect;
};

#endif //NAMEBATTLER_DEBUGMESSAGE_H
