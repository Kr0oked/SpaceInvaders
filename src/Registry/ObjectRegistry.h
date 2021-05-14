#ifndef SPACEINVADERS_OBJECTREGISTRY_H
#define SPACEINVADERS_OBJECTREGISTRY_H

#include <map>
#include <string>
#include <Model/Object.h>

class ObjectRegistry {
public:
    typedef std::map<std::string, object *> MapObject;

    static ObjectRegistry *Instance();

    object *GetObject(const std::string &);

private:
    ObjectRegistry() = default;;

    ObjectRegistry(ObjectRegistry const &) {};

    void operator=(ObjectRegistry const &) {};
    static ObjectRegistry *instance;
    MapObject mapObject;
};

#endif //SPACEINVADERS_OBJECTREGISTRY_H
