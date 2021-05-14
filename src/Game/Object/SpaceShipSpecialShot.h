#ifndef SPACEINVADERS_SPACESHIPSPECIALSHOT_H
#define SPACEINVADERS_SPACESHIPSPECIALSHOT_H

#include <Game/IShot.h>
#include "Rectangle.h"

class SpaceShipSpecialShot : public Rectangle, public IShot {
public:
    explicit SpaceShipSpecialShot(glm::vec2);

    bool Idle(float) override;

    int Hit(int) override;

    void SetPower(int) override;

private:
    int power;
};

#endif //SPACEINVADERS_SPACESHIPSPECIALSHOT_H
