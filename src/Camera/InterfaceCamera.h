#ifndef SPACEINVADERS_INTERFACECAMERA_H
#define SPACEINVADERS_INTERFACECAMERA_H

#include "ICamera.h"

class InterfaceCamera : public ICamera {
public:
    InterfaceCamera(GLdouble, GLdouble, GLdouble, GLdouble);

    void applyModelViewMatrix() override;

    void applyProjectionMatrix() override;

private:
    GLdouble left;
    GLdouble right;
    GLdouble bottom;
    GLdouble top;
};

#endif //SPACEINVADERS_INTERFACECAMERA_H
