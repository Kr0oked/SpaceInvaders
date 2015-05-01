#include <Registry/ObjectRegistry.h>
#include "SpaceInvaderShot.h"

SpaceInvaderShot::SpaceInvaderShot(glm::vec2 position) : Rectangle(position, 0.02f, 0.02f, 1.0f, 1.0f, 1.0) {
    SetPower(1);
}

bool SpaceInvaderShot::Idle(float elapsedTime) {
    if (GetLastTime() == 0.0f)
    {
        Rectangle::Idle(elapsedTime);
    }

    float deltaTime = elapsedTime - GetLastTime();

    Move(glm::vec2(0.0f, -0.5f) * deltaTime);
    Rectangle::Idle(elapsedTime);

    if (IsOutOfMap()) {
        return true;
    }
    return false;
}

int SpaceInvaderShot::Hit(int targetLives) {
    int difference = power - targetLives;
    if (difference >= 0) {
        power = difference;
        return 0;
    }
    else {
        int ret = targetLives - power;
        ObjectRegistry<SpaceInvaderShot>::Instance()->Unregister(this);
        return ret;
    }
}

int SpaceInvaderShot::SetPower(int power_) {
    power = power_;
}
