#ifndef SPACEINVADERS_RECTANGLE_H
#define SPACEINVADERS_RECTANGLE_H

#include <Object/IObject.h>

class Rectangle : public IObject {
public:
    Rectangle();
    Rectangle(glm::vec2 position, float width, float height, int texture);
    Rectangle(glm::vec2 position, float width, float height, float red, float green, float blue);
    virtual bool Idle(float);
    virtual void Draw() const;
    virtual void Move(glm::vec2);
    virtual bool IsOutOfMap() const;
    virtual glm::vec2 GetPosition() const;
    virtual void SetPosition(glm::vec2);
    bool Intersect(Rectangle*);
    float GetWidth() const;
    float GetHeight() const;
    float GetXLeft();
    float GetXRight();
    float GetYDown();
    float GetYUp();
    float GetLastTime() const;
    bool IsUsingTexture() const;
    void SetWidth(float);
    void SetHeight(float);
    void SetSurface(int);
    void SetSurface(float, float, float);

private:
    void UpdateVertices();
    bool IsValueInRange(float value, float min, float max);
    glm::vec2 position;
    float width;
    float height;
    float xLeft;
    float xRight;
    float yDown;
    float yUp;
    float lastTime;
    int texture;
    float red;
    float green;
    float blue;
    bool useTexture;
};

#endif //SPACEINVADERS_RECTANGLE_H
