#ifndef SPACEINVADERS_TEXTURELOADER_H
#define SPACEINVADERS_TEXTURELOADER_H

#include <string>
#include <map>

#include "ITextureLoader.h"

class TextureLoader : public ITextureLoader {
public:
    typedef std::map<std::string, int> MapTexture;
    virtual int Load(const std::string&);

private:
    mutable MapTexture mapTexture;
};

#endif //SPACEINVADERS_TEXTURELOADER_H
