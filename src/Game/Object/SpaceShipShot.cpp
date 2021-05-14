#include <Registry/GameRegistry.h>
#include "SpaceShipShot.h"

SpaceShipShot::SpaceShipShot(glm::vec2 position)
        : Rectangle(position, 0.01f, 0.01f, 0.01f, 0.9f, 0.1f, 0.1f, 1.0f) {
    SetPower(1);
}

bool SpaceShipShot::Idle(float elapsedTime) {
    if (GetLastTime() == 0.0f) {
        Rectangle::Idle(elapsedTime);
    }

    float deltaTime = elapsedTime - GetLastTime();

    Move(glm::vec2(0.0f, 0.8f) * deltaTime);
    Rectangle::Idle(elapsedTime);

    return IsOutOfMap();
}

int SpaceShipShot::Hit(int targetLives) {
    int difference = power - targetLives;
    if (difference >= 0) {
        power = difference;
        return 0;
    } else {
        int ret = targetLives - power;
        GameRegistry<SpaceShipShot>::Instance()->Unregister(this);
        return ret;
    }
}

void SpaceShipShot::SetPower(int power_) {
    power = power_;
}
