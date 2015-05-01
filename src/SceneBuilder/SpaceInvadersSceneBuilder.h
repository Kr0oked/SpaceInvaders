#ifndef SPACEINVADERS_SPACEINVADERSSCENEBUILDER_H
#define SPACEINVADERS_SPACEINVADERSSCENEBUILDER_H

#include "ISceneBuilder.h"

class SpaceInvadersSceneBuilder : public ISceneBuilder {
public:
    virtual void BuildScene();
    virtual void ResetScene();
};

#endif //SPACEINVADERS_SPACEINVADERSSCENEBUILDER_H
