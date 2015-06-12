#ifndef SPACEINVADERS_SPACEINVADER_H
#define SPACEINVADERS_SPACEINVADER_H

#include <Game/IShootable.h>
#include "Rectangle.h"

class SpaceInvader : public Rectangle, public IShootable {
public:
    SpaceInvader();
    virtual bool Idle(float);
    virtual void Draw() const;
    virtual int GetLives() const;
    virtual void SetLives(int);

private:
    void Shoot() const;
    bool animationState;
    int lives;
};

#endif //SPACEINVADERS_SPACEINVADER_H
