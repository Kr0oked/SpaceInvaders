#ifndef SPACEINVADERS_SPACESHIP_H
#define SPACEINVADERS_SPACESHIP_H

#include <Game/IShootable.h>
#include <Game/IInterface.h>
#include "Rectangle.h"

class SpaceShip : public Rectangle, public IInterface, public IShootable {
public:
    SpaceShip();
    virtual bool Idle(float);
    virtual void Draw() const;
    virtual int GetLives() const;
    virtual void SetLives(int);
    virtual void SetPosition(glm::vec2);
    virtual void DrawInterface();

private:
    void MoveLeft(float);
    void MoveRight(float);
    void Shoot();
    void ShootSpecial();
    int lives;
    float lastShot;
    float immune;
    bool specialShot;
    int texLive;
    float rotation;
};

#endif //SPACEINVADERS_SPACESHIP_H
