#ifndef SPACEINVADERS_SCENECAMERA_H
#define SPACEINVADERS_SCENECAMERA_H

#include "ICamera.h"

class SceneCamera : public ICamera {
public:
    SceneCamera(GLint, GLint, GLdouble, GLdouble, GLdouble);

    void applyModelViewMatrix() override;

    void applyProjectionMatrix() override;

    void setScreenWidth(GLint);

    void setScreenHeight(GLint);

    void setEye(glm::vec3);

    void setCenter(glm::vec3);

    void setUp(glm::vec3);

private:
    GLint screenWidth;
    GLint screenHeight;
    GLdouble fovy;
    GLdouble zNear;
    GLdouble zFar;
    glm::vec3 eye{};
    glm::vec3 center{};
    glm::vec3 up{};
};

#endif //SPACEINVADERS_SCENECAMERA_H
