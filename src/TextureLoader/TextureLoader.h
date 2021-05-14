#ifndef SPACEINVADERS_TEXTURELOADER_H
#define SPACEINVADERS_TEXTURELOADER_H

#include <string>
#include <map>

#include "ITextureLoader.h"

class TextureLoader : public ITextureLoader {
public:
    typedef std::map<std::string, int> MapTexture;

    static TextureLoader *Instance();

    unsigned int Load(const std::string &) override;

private:
    TextureLoader() = default;;

    TextureLoader(TextureLoader const &) {};

    void operator=(TextureLoader const &) {};
    static TextureLoader *instance;
    MapTexture mapTexture;
};

#endif //SPACEINVADERS_TEXTURELOADER_H
