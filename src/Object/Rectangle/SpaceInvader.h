#ifndef SPACEINVADERS_SPACEINVADER_H
#define SPACEINVADERS_SPACEINVADER_H

#include <Object/IShootable.h>
#include "Rectangle.h"

class SpaceInvader : public Rectangle, public IShootable {
public:
    SpaceInvader();
    virtual bool Idle(float);
    virtual int GetLives() const;
    virtual void SetLives(int);

private:
    void Shoot() const;
    void ChangeTexture();
    int tex1;
    int tex2;
    int texCurrent;
    int lives;
    float lastAction;
};

#endif //SPACEINVADERS_SPACEINVADER_H
