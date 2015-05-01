#ifndef SPACEINVADERS_ITEXTURELOADER_H
#define SPACEINVADERS_ITEXTURELOADER_H

#include <string>

class ITextureLoader {
public:
    virtual int Load(const std::string&) = 0;
};

#endif //SPACEINVADERS_ITEXTURELOADER_H
