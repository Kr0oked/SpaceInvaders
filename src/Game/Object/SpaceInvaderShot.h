#ifndef SPACEINVADERS_SPACEINVADERSHOT_H
#define SPACEINVADERS_SPACEINVADERSHOT_H

#include <Game/IShot.h>
#include "Rectangle.h"

class SpaceInvaderShot : public Rectangle, public IShot {
public:
    explicit SpaceInvaderShot(glm::vec2);

    bool Idle(float) override;

    int Hit(int) override;

    void SetPower(int) override;

private:
    int power;
};

#endif //SPACEINVADERS_SPACEINVADERSHOT_H
