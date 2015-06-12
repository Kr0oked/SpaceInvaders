#ifndef SPACEINVADERS_SPACEINVADERSHOT_H
#define SPACEINVADERS_SPACEINVADERSHOT_H

#include <Game/IShot.h>
#include "Rectangle.h"

class SpaceInvaderShot : public Rectangle, public IShot {
public:
    SpaceInvaderShot(glm::vec2);
    virtual bool Idle(float);
    virtual int Hit(int);
    virtual void SetPower(int);

private:
    int power;
};

#endif //SPACEINVADERS_SPACEINVADERSHOT_H
