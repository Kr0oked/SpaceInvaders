#include <GL/glew.h>
#include "SceneCamera.h"

SceneCamera::SceneCamera(GLint screenWidth_, GLint screenHeight_, GLdouble fovy_, GLdouble zNear_, GLdouble zFar_) {
    screenWidth = screenWidth_;
    screenHeight = screenHeight_;
    fovy = fovy_;
    zNear = zNear_;
    zFar = zFar_;
}

void SceneCamera::applyModelViewMatrix() {
    gluLookAt(eye.x, eye.y, eye.z,
              center.x, center.y, center.z,
              up.x, up.y, up.z);

    /*gluLookAt(0.0, -1.5, 0.5,
              0.0, 1.5, 0.0,
              0.0, 1.0, 0.0);*/
}

void SceneCamera::applyProjectionMatrix() {
    const double aspect = (double) screenWidth / screenHeight;
    gluPerspective(fovy, aspect, zNear, zFar);
}

void SceneCamera::setScreenWidth(GLint screenWidth_) {
    screenWidth = screenWidth_;
}

void SceneCamera::setScreenHeight(GLint screenHeight_) {
    screenHeight = screenHeight_;
}
void SceneCamera::setEye(glm::vec3 eye_) {
    eye = eye_;
}

void SceneCamera::setCenter(glm::vec3 center_) {
    center = center_;
}

void SceneCamera::setUp(glm::vec3 up_) {
    up = up_;
}
