#ifndef SPACEINVADERS_SPACEINVADERSSCENEBUILDER_H
#define SPACEINVADERS_SPACEINVADERSSCENEBUILDER_H

#include "ISceneBuilder.h"

class SpaceInvadersSceneBuilder : public ISceneBuilder {
public:
    void BuildScene() override;

    void ResetScene() override;
};

#endif //SPACEINVADERS_SPACEINVADERSSCENEBUILDER_H
