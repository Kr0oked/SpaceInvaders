#ifndef SPACEINVADERS_SPACESHIPSHOT_H
#define SPACEINVADERS_SPACESHIPSHOT_H

#include <Object/IShot.h>
#include "Rectangle.h"

class SpaceShipShot : public Rectangle, public IShot {
public:
    SpaceShipShot(glm::vec2);
    virtual bool Idle(float);
    virtual int Hit(int);
    virtual int SetPower(int);

private:
    int power;
};

#endif //SPACEINVADERS_SPACESHIPSHOT_H
