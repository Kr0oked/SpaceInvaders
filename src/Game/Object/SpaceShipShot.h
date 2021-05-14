#ifndef SPACEINVADERS_SPACESHIPSHOT_H
#define SPACEINVADERS_SPACESHIPSHOT_H

#include <Game/IShot.h>
#include "Rectangle.h"

class SpaceShipShot : public Rectangle, public IShot {
public:
    explicit SpaceShipShot(glm::vec2);

    bool Idle(float) override;

    int Hit(int) override;

    void SetPower(int) override;

private:
    int power;
};

#endif //SPACEINVADERS_SPACESHIPSHOT_H
