#ifndef SPACEINVADERS_GAMEWIN_H
#define SPACEINVADERS_GAMEWIN_H

#include <Game/IInterface.h>

class GameWin : public IInterface {
public:
    void DrawInterface() override;
};

#endif //SPACEINVADERS_GAMEWIN_H
