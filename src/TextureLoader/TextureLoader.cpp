#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <iostream>
#include "TextureLoader.h"

TextureLoader *TextureLoader::instance = nullptr;

TextureLoader *TextureLoader::Instance() {
    if (!instance) {
        instance = new TextureLoader;
    }

    return instance;
}

unsigned int TextureLoader::Load(const std::string &filename) {
    unsigned int textureId = 0;
    auto it = mapTexture.find(filename);

    if (it == mapTexture.end()) {
        textureId = SOIL_load_OGL_texture(filename.c_str(),
                                          SOIL_LOAD_AUTO,
                                          SOIL_CREATE_NEW_ID,
                                          SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        mapTexture.insert(std::pair<std::string, int>(filename, textureId));

        if (textureId == 0) {
            printf("Failed loading texture from \"%s\"", filename.c_str());
        } else {
            printf("Loaded texture from \"%s\" with ID %i\n", filename.c_str(), textureId);

        }
    } else {
        textureId = (*it).second;
    }

    return textureId;
}
