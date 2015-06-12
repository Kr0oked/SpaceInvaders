#ifndef SPACEINVADERS_GAMEREGISTRY_H
#define SPACEINVADERS_GAMEREGISTRY_H

#include <list>

template <class T>
class GameRegistry {
public:
    typedef typename std::list<T*> ListObject;
    typedef typename ListObject::iterator iterator;

    static GameRegistry<T>* Instance() {
        if (!instance) {
            instance = new GameRegistry<T>;
        }
        return instance;
    }

    void Register(T* object) {
        listObject.push_back(object);
    }

    void Unregister(T* object) {
        listObject.remove(object);
    }

    iterator Unregister(iterator it) {
        return listObject.erase(it);
    }

    void UnregisterAll() {
        listObject.clear();
    }

    iterator Begin() {
        return listObject.begin();
    }

    iterator End() {
        return listObject.end();
    }

private:
    GameRegistry() {};
    GameRegistry(GameRegistry const&) {};
    GameRegistry & operator = (GameRegistry const&) {};
    static GameRegistry<T>* instance;
    ListObject listObject;
};

template <class T>
GameRegistry<T>* GameRegistry<T>::instance = 0;

#endif //SPACEINVADERS_GAMEREGISTRY_H
