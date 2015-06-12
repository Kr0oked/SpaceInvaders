#ifndef SPACEINVADERS_BACKGROUND_H
#define SPACEINVADERS_BACKGROUND_H

#include <Game/IObject.h>
#include <Game/IBackground.h>

class Background : public IBackground {
public:
    virtual void DrawBackground() const;
};

#endif //SPACEINVADERS_BACKGROUND_H
