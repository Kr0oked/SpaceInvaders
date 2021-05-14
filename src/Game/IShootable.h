#ifndef SPACEINVADERS_ISHOOTABLE_H
#define SPACEINVADERS_ISHOOTABLE_H

class IShootable {
public:
    virtual int GetLives() const = 0;

    virtual void SetLives(int) = 0;
};

#endif //SPACEINVADERS_ISHOOTABLE_H
