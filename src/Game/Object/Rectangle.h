#ifndef SPACEINVADERS_RECTANGLE_H
#define SPACEINVADERS_RECTANGLE_H

#include <glm/vec3.hpp>
#include <Game/IObject.h>

class Rectangle : public IObject {
public:
    Rectangle();
    Rectangle(glm::vec2 position, float width, float height, float depth, float red, float green, float blue, float aplpha);
    virtual bool Idle(float);
    virtual void Draw() const;
    virtual void Move(glm::vec2);
    virtual bool IsOutOfMap() const;
    virtual glm::vec2 GetPosition() const;
    virtual void SetPosition(glm::vec2);
    bool Intersect(Rectangle*);
    float GetWidth() const;
    float GetHeight() const;
    float GetXLeft() const;
    float GetXRight() const;
    float GetYDown() const;
    float GetYUp() const;
    float GetLastTime() const;
    float GetRed() const;
    float GetGreen() const;
    float GetBlue() const;
    float GetAlpha() const;
    void SetWidth(float);
    void SetHeight(float);
    void SetDepth(float);
    void SetSurface(float, float, float, float);

private:
    void UpdateVertices();
    bool IsValueInRange(float value, float min, float max);
    glm::vec2 position;
    float width;
    float height;
    float depth;
    float xLeft;
    float xRight;
    float yDown;
    float yUp;
    float lastTime;
    float red;
    float green;
    float blue;
    float alpha;
};

#endif //SPACEINVADERS_RECTANGLE_H
