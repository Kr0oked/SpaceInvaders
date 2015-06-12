#ifndef SPACEINVADERS_ICAMERA_H
#define SPACEINVADERS_ICAMERA_H

#include <glm/glm.hpp>

class ICamera {
public:
    virtual void applyModelViewMatrix() = 0;
    virtual void applyProjectionMatrix() = 0;
};

#endif //SPACEINVADERS_ICAMERA_H
