#include <Factory/Factory.h>
#include <Registry/GameRegistry.h>

Item::Item(glm::vec2 position) : Rectangle() {
    SetWidth(0.03f);
    SetHeight(0.03f);
    SetDepth(0.03f);
    SetPosition(position);
    SetSurface(1.0f, 1.0f, 0.0f, 1.0f);
}

bool Item::Idle(float elapsedTime) {
    if (GetLastTime() == 0.0f) {
        Rectangle::Idle(elapsedTime);
    }

    float deltaTime = elapsedTime - GetLastTime();

    Move(glm::vec2(0.0f, -0.3f) * deltaTime);
    Rectangle::Idle(elapsedTime);

    return IsOutOfMap();
}

void Item::Activate() {
    GameRegistry<Item>::Instance()->Unregister(this);
}
