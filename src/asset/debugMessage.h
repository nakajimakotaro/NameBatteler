//
// Created by nakajimakotaro on 2018/01/02.
//

#ifndef NAMEBATTLER_DEBUGMESSAGE_H
#define NAMEBATTLER_DEBUGMESSAGE_H


#include <vector>
#include "../common/gameObject.h"
#include "../common/rect.h"

class DebugMessage : public GameObject{
private:
    std::vector<std::pair<std::string, std::string>> messageList;
public:
    DebugMessage(std::weak_ptr<Scene> scene);
    void postUpdate() override;
    void draw() override;
    Type getType() override;
    void set(std::string name, std::string value);
};

#endif //NAMEBATTLER_DEBUGMESSAGE_H
