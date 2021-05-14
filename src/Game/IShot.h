#ifndef SPACEINVADERS_ISHOT_H
#define SPACEINVADERS_ISHOT_H

class IShot {
public:
    virtual int Hit(int) = 0;

    virtual void SetPower(int) = 0;
};

#endif //SPACEINVADERS_ISHOT_H
