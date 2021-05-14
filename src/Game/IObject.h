#ifndef SPACEINVADERS_IOBJECT_H
#define SPACEINVADERS_IOBJECT_H

#include <glm/vec2.hpp>

class IObject {
public:
    virtual bool Idle(float) = 0;

    virtual void Draw() const = 0;

    virtual void Move(glm::vec2) = 0;

    virtual bool IsOutOfMap() const = 0;

    virtual glm::vec2 GetPosition() const = 0;

    virtual void SetPosition(glm::vec2) = 0;
};

#endif //SPACEINVADERS_IOBJECT_H
