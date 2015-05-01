#ifndef SPACEINVADERS_OBJECTREGISTRY_H
#define SPACEINVADERS_OBJECTREGISTRY_H

#include <list>

template <class T>
class ObjectRegistry {
public:
    typedef typename std::list<T*> ListObject;
    typedef typename ListObject::iterator iterator;

    static ObjectRegistry<T>* Instance() {
        if (!instance) {
            instance = new ObjectRegistry<T>;
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
    ObjectRegistry() {};
    ObjectRegistry(ObjectRegistry const&) {};
    ObjectRegistry& operator = (ObjectRegistry const&) {};
    static ObjectRegistry<T>* instance;
    ListObject listObject;
};

template <class T>
ObjectRegistry<T>* ObjectRegistry<T>::instance = 0;

#endif //SPACEINVADERS_OBJECTREGISTRY_H
