#ifndef SPACEINVADERS_ITEM_H
#define SPACEINVADERS_ITEM_H

#include <Game/IItem.h>
#include "Rectangle.h"

class Item : public Rectangle, public IItem {
public:
    explicit Item(glm::vec2);

    bool Idle(float) override;

    void Activate() override;
};

#endif //SPACEINVADERS_ITEM_H
