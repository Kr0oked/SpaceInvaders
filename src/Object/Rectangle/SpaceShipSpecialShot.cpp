#include <Registry/ObjectRegistry.h>
#include "SpaceShipSpecialShot.h"

SpaceShipSpecialShot::SpaceShipSpecialShot(glm::vec2 position) : Rectangle(position, 0.02f, 0.05f, 0.9f, 0.1f, 0.1) {
    SetPower(10);
}

bool SpaceShipSpecialShot::Idle(float elapsedTime) {
    if (GetLastTime() == 0.0f)
    {
        Rectangle::Idle(elapsedTime);
    }

    float deltaTime = elapsedTime - GetLastTime();

    Move(glm::vec2(0.0f, 0.8f) * deltaTime);
    Rectangle::Idle(elapsedTime);

    if (IsOutOfMap()) {
        return true;
    }
    return false;
}

int SpaceShipSpecialShot::Hit(int targetLives) {
    int difference = power - targetLives;
    if (difference >= 0) {
        power = difference;
        return 0;
    }
    else {
        int ret = targetLives - power;
        ObjectRegistry<SpaceShipSpecialShot>::Instance()->Unregister(this);
        return ret;
    }
}

int SpaceShipSpecialShot::SetPower(int power_) {
    power = power_;
}
