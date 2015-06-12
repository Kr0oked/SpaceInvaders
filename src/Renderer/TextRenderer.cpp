#include <GL/glut.h>
#include <Model/Text.h>
#include "TextRenderer.h"

void TextRenderer::Render(const text* tex) {
    glRasterPos2f(tex->position.x, tex->position.y);

    for(std::string::const_iterator it = tex->string.begin(); it != tex->string.end(); ++it) {
        switch (tex->size) {
            case 10:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *it);
                break;
            case 12:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *it);
                break;
            case 18:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it);
                break;
            default:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *it);
                break;
        }
    }
}