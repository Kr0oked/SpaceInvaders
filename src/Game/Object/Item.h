#ifndef SPACEINVADERS_ITEM_H
#define SPACEINVADERS_ITEM_H

#include <Game/IItem.h>
#include "Rectangle.h"

class Item : public Rectangle, public IItem {
public:
    Item(glm::vec2);
    virtual bool Idle(float);
    virtual void Activate();
};

#endif //SPACEINVADERS_ITEM_H
