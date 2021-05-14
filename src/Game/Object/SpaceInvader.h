#ifndef SPACEINVADERS_SPACEINVADER_H
#define SPACEINVADERS_SPACEINVADER_H

#include <Game/IShootable.h>
#include "Rectangle.h"

class SpaceInvader : public Rectangle, public IShootable {
public:
    SpaceInvader();

    bool Idle(float) override;

    void Draw() const override;

    int GetLives() const override;

    void SetLives(int) override;

private:
    void Shoot() const;

    int lives;
};

#endif //SPACEINVADERS_SPACEINVADER_H
