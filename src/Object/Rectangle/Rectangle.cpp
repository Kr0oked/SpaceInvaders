#include <GL/glew.h>
#include <glm/common.hpp>
#include "Rectangle.h"

Rectangle::Rectangle()
        : width(0.1f), height(0.1f), xLeft(0.0f), xRight(0.0f), yDown(0.0f), yUp(0.0f), lastTime(0.0f),
          texture(0), red(1.0f), green(1.0f), blue(1.0f), useTexture(false) {
    SetPosition(glm::vec2(0.0f, 0.0f));
}

Rectangle::Rectangle(glm::vec2 position, float width_, float height_, int texture_)
        : lastTime(0.0f), red(1.0f), green(1.0f), blue(1.0f), useTexture(true) {
    width = width_;
    height = height_;
    texture = texture_;
    SetPosition(position);
}

Rectangle::Rectangle(glm::vec2 position, float width_, float height_, float red_, float green_, float blue_)
        : lastTime(0.0f), texture(0), useTexture(false) {
    width = width_;
    height = height_;
    red = red_;
    green = green_;
    blue = blue_;
    SetPosition(position);
}

bool Rectangle::Idle(float elapsedTime) {
    lastTime = elapsedTime;
    return false;
}

void Rectangle::Draw() const {
    if (useTexture)
    {
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, texture);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(xLeft, yDown);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(xLeft, yUp);
        glTexCoord2f(1.0f, 1.0f); glVertex2f(xRight, yUp);
        glTexCoord2f(1.0f, 0.0f); glVertex2f(xRight, yDown);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    else
    {
        glEnable(GL_COLOR_MATERIAL);
        glColor3f(red, green, blue);
        glBegin(GL_QUADS);
        glVertex2f(xLeft, yDown);
        glVertex2f(xLeft, yUp);
        glVertex2f(xRight, yUp);
        glVertex2f(xRight, yDown);
        glEnd();
    }
}

void Rectangle::Move(glm::vec2 move) {
    SetPosition(glm::clamp(GetPosition() + move,
                           glm::vec2(-1.0f + GetWidth() / 2, -0.81f + GetHeight() / 2),
                           glm::vec2(1.0f - GetWidth() / 2, 1.0f - GetHeight() / 2)));
}

bool Rectangle::IsOutOfMap() const {
    bool isXLeftOut = xLeft <= -1.0f || xLeft >= 1.0f;
    bool isXRightOut = xRight <= -1.0f || xRight >= 1.0f;
    bool isYDownOut = yDown <= -0.81f || yDown >= 1.0f;
    bool isYUpOut = yUp <= -0.81f || yUp >= 1.0f;

    return isXLeftOut || isXRightOut || isYDownOut || isYUpOut;
}

glm::vec2 Rectangle::GetPosition() const {
    return position;
}

void Rectangle::SetPosition(glm::vec2 position_) {
    position = position_;
    UpdateVertices();
}

bool Rectangle::IsUsingTexture() const {
    return useTexture;
}

bool Rectangle::Intersect(Rectangle* rect) {
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

float Rectangle::GetXLeft() {
    return xLeft;
}

float Rectangle::GetXRight() {
    return xRight;
}

float Rectangle::GetYDown() {
    return yDown;
}

float Rectangle::GetYUp() {
    return yUp;
}

float Rectangle::GetLastTime() const {
    return lastTime;
}

void Rectangle::SetWidth(float width_) {
    width = width_;
    UpdateVertices();
}

void Rectangle::SetHeight(float height_) {
    height = height_;
    UpdateVertices();
}

void Rectangle::SetSurface(int texture_) {
    texture = texture_;
    useTexture = true;
}

void Rectangle::SetSurface(float red_, float green_, float blue_) {
    red = red_;
    green = green_;
    blue = blue_;
    useTexture = false;
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
