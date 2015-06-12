#include <GL/glew.h>
#include <TextureLoader/ITextureLoader.h>
#include <TextureLoader/TextureLoader.h>
#include "GameWin.h"

void GameWin::DrawInterface() {
    ITextureLoader* textureLoader = TextureLoader::Instance();
    int texGameWin = textureLoader->Load("data/img/game_win.png");

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texGameWin);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}