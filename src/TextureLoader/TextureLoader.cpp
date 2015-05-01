#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include "TextureLoader.h"

int TextureLoader::Load(const std::string& filename) {
    int textureId = 0;
    MapTexture::iterator it = mapTexture.find(filename);

    if (it == mapTexture.end()) {
        textureId = SOIL_load_OGL_texture(filename.c_str(),
                                            SOIL_LOAD_AUTO,
                                            SOIL_CREATE_NEW_ID,
                                            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        mapTexture.insert(std::pair<std::string, int>(filename, textureId));
    }
    else {
        textureId = (*it).second;
    }

    return textureId;
}
