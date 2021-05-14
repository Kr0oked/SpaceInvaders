#include <GL/glew.h>
#include "InterfaceCamera.h"

InterfaceCamera::InterfaceCamera(GLdouble left_, GLdouble right_, GLdouble bottom_, GLdouble top_) {
    left = left_;
    right = right_;
    bottom = bottom_;
    top = top_;
}

void InterfaceCamera::applyModelViewMatrix() {
}

void InterfaceCamera::applyProjectionMatrix() {
    gluOrtho2D(left, right, bottom, top);
}
