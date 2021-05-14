#ifndef SPACEINVADERS_INPUTREGISTRY_H
#define SPACEINVADERS_INPUTREGISTRY_H

#include <map>

extern const int KEY_LEFT;
extern const int KEY_UP;
extern const int KEY_RIGHT;
extern const int KEY_SPACEBAR;

#include <map>

class InputRegistry {
public:
    typedef std::map<int, bool> MapKey;

    static InputRegistry *Instance();

    void RegisterKey(int);

    void UnregisterKey(int);

    bool IsKeyRegistered(int) const;

private:
    InputRegistry() = default;;

    InputRegistry(InputRegistry const &) {};

    void operator=(InputRegistry const &) {};
    static InputRegistry *instance;
    MapKey mapKey;
};

#endif //SPACEINVADERS_INPUTREGISTRY_H
