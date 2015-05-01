#include "InputRegistry.h"

const int KEY_LEFT = 1100;
const int KEY_UP = 1101;
const int KEY_RIGHT = 1102;
const int KEY_DOWN = 1103;
const int KEY_SPACEBAR = 32;

InputRegistry* InputRegistry::instance = 0;

InputRegistry* InputRegistry::Instance() {
    if (!instance) {
        instance = new InputRegistry;
    }

    return instance;
}

void InputRegistry::RegisterKey(int key) {
    mapKey[key] = true;
}

void InputRegistry::UnregisterKey(int key) {
    mapKey[key] = false;
}

bool InputRegistry::IsKeyRegistered(int key) const {
    bool isKeyRegistered;
    MapKey::const_iterator it = mapKey.find(key);

    if (it == mapKey.end()) {
        isKeyRegistered = false;
    }
    else {
        isKeyRegistered = (*it).second;
    }

    return isKeyRegistered;
}
