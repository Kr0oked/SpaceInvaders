#ifndef SPACEINVADERS_SPACESHIP_H
#define SPACEINVADERS_SPACESHIP_H

#include <Object/IShootable.h>
#include "Rectangle.h"

class SpaceShip : public Rectangle, public IShootable {
public:
    SpaceShip();
    virtual bool Idle(float);
    virtual void Draw() const;
    virtual int GetLives() const;
    virtual void SetLives(int);

private:
    void MoveLeft(float);
    void MoveRight(float);
    void Shoot();
    void ShootSpecial();
    Rectangle* liveIndicator;
    Rectangle* specialShotIndicator;
    int texNormal;
    int texImmune;
    int lives;
    float lastShot;
    float immune;
    bool specialShot;
};

#endif //SPACEINVADERS_SPACESHIP_H
