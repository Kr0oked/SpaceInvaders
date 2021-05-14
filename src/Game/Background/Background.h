#ifndef SPACEINVADERS_BACKGROUND_H
#define SPACEINVADERS_BACKGROUND_H

#include <Game/IObject.h>
#include <Game/IBackground.h>

class Background : public IBackground {
public:
    void DrawBackground() const override;
};

#endif //SPACEINVADERS_BACKGROUND_H
