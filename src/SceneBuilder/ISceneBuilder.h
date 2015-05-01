#ifndef SPACEINVADERS_ISCENEBUILDER_H
#define SPACEINVADERS_ISCENEBUILDER_H

class ISceneBuilder {
public:
    virtual void BuildScene() = 0;
    virtual void ResetScene() = 0;
};

#endif //SPACEINVADERS_ISCENEBUILDER_H
