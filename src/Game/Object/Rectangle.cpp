#include <GL/glew.h>
#include <glm/common.hpp>
#include <GL/freeglut_std.h>
#include "Rectangle.h"

Rectangle::Rectangle()
        : width(0.1f), height(0.1f), depth(0.1f), xLeft(0.0f), xRight(0.0f), yDown(0.0f), yUp(0.0f), lastTime(0.0f),
          red(1.0f), green(1.0f), blue(1.0f), alpha(1.0f) {
    SetPosition(glm::vec2(0.0f, 0.0f));
}

Rectangle::Rectangle(glm::vec2 position, float width_, float depth_, float height_,
                     float red_, float green_, float blue_, float alpha_) : lastTime(0.0f) {
    width = width_;
    height = height_;
    depth = depth_;
    red = red_;
    green = green_;
    blue = blue_;
    alpha = alpha_;
    SetPosition(position);
}

bool Rectangle::Idle(float elapsedTime) {
    lastTime = elapsedTime;
    return false;
}

void Rectangle::Draw() const {
    float scaleHeight = height / width;
    float scaleDepth = depth / width;

    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor4f(red, green, blue, alpha);
    glTranslatef(position.x, position.y, 0);
    glScalef(1.0f, scaleHeight, scaleDepth);

    glutSolidCube(width);

    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
}

void Rectangle::Move(glm::vec2 move) {
    SetPosition(glm::clamp(GetPosition() + move,
                           glm::vec2(-1.0f + GetWidth() / 2, -3.0f + GetHeight() / 2),
                           glm::vec2(1.0f - GetWidth() / 2, 3.0f - GetHeight() / 2)));
}

bool Rectangle::IsOutOfMap() const {
    bool isXLeftOut = xLeft <= -1.0f || xLeft >= 1.0f;
    bool isXRightOut = xRight <= -1.0f || xRight >= 1.0f;
    bool isYDownOut = yDown <= -3.0f || yDown >= 3.0f;
    bool isYUpOut = yUp <= -3.0f || yUp >= 3.0f;

    return isXLeftOut || isXRightOut || isYDownOut || isYUpOut;
}

glm::vec2 Rectangle::GetPosition() const {
    return position;
}

void Rectangle::SetPosition(glm::vec2 position_) {
    position = position_;
    UpdateVertices();
}

bool Rectangle::Intersect(Rectangle *rect) const {
    GLfloat xLeft2 = rect->GetXLeft();
    GLfloat xRight2 = rect->GetXRight();
    GLfloat yDown2 = rect->GetYDown();
    GLfloat yUp2 = rect->GetYUp();

    bool xOverlap = IsValueInRange(xLeft, xLeft2, xRight2) ||
                    IsValueInRange(xLeft2, xLeft, xRight);

    bool yOverlap = IsValueInRange(yDown, yDown2, yUp2) ||
                    IsValueInRange(yDown2, yDown, yUp);

    return xOverlap && yOverlap;
}

float Rectangle::GetWidth() const {
    return width;
}

float Rectangle::GetHeight() const {
    return height;
}

float Rectangle::GetXLeft() const {
    return xLeft;
}

float Rectangle::GetXRight() const {
    return xRight;
}

float Rectangle::GetYDown() const {
    return yDown;
}

float Rectangle::GetYUp() const {
    return yUp;
}

float Rectangle::GetLastTime() const {
    return lastTime;
}

float Rectangle::GetRed() const {
    return red;
}

float Rectangle::GetGreen() const {
    return green;
}

float Rectangle::GetBlue() const {
    return blue;
}

float Rectangle::GetAlpha() const {
    return alpha;
}

void Rectangle::SetWidth(float width_) {
    width = width_;
    UpdateVertices();
}

void Rectangle::SetHeight(float height_) {
    height = height_;
    UpdateVertices();
}

void Rectangle::SetDepth(float depth_) {
    depth = depth_;
    UpdateVertices();
}

void Rectangle::SetSurface(float red_, float green_, float blue_, float alpha_) {
    red = red_;
    green = green_;
    blue = blue_;
    alpha = alpha_;
}

void Rectangle::UpdateVertices() {
    xLeft = position.x - width / 2;
    xRight = position.x + width / 2;
    yDown = position.y - height / 2;
    yUp = position.y + height / 2;
}

bool Rectangle::IsValueInRange(float value, float min, float max) {
    return (value >= min) && (value <= max);
}
