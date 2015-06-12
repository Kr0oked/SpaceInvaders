#ifndef SPACEINVADERS_OBJECTLOADER_H
#define SPACEINVADERS_OBJECTLOADER_H

#include <string>
#include <Model/Object.h>

class ObjectLoader {
public:
    object* Load(const std::string&, const std::string&);
};

#endif //SPACEINVADERS_OBJECTLOADER_H
