#ifndef SPACEINVADERS_SPACESHIP_H
#define SPACEINVADERS_SPACESHIP_H

#include <Game/IShootable.h>
#include <Game/IInterface.h>
#include "Rectangle.h"

class SpaceShip : public Rectangle, public IInterface, public IShootable {
public:
    SpaceShip();

    bool Idle(float) override;

    void Draw() const override;

    int GetLives() const override;

    void SetLives(int) override;

    void SetPosition(glm::vec2) override;

    void DrawInterface() override;

private:
    void MoveLeft(float);

    void MoveRight(float);

    void Shoot();

    void ShootSpecial();

    int lives;
    float lastShot;
    float immune;
    bool specialShot;
    unsigned int texLive;
    float rotation;
};

#endif //SPACEINVADERS_SPACESHIP_H
