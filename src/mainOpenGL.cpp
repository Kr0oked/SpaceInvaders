#include <GL/glew.h>
#include <GL/glut.h>
#include "Application.h"

const int ID_ESC = 27;

Application* application = 0;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    application->OnDisplay();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    int x;
    int y;
    int size;

    /* Scale Viewport to Window Size */
    if (width >= height)
    {
        size = height;
        x = int((width - height) / 2 + 0.5);
        y = 0;
    }
    else
    {
        size = width;
        x = 0;
        y = int((height - width) / 2 + 0.5);
    }

    glViewport(x, y, size, size);						// Reset The Current Viewport
    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix
    glMatrixMode(GL_MODELVIEW);							// Select The ModelView Matrix
    glLoadIdentity();
}

void idle(void) {
    int elapsedTime = glutGet(GLUT_ELAPSED_TIME);
    float sec = (float)elapsedTime / 1000;
    application->OnIdle(sec);
    glutPostWindowRedisplay(1);
}

void keyboard(unsigned char key, int x, int y) {
    application->KeyOn(key);
    switch (key) {
        case 'f':
            glutFullScreen();
            break;
        case ID_ESC:
            exit(0);
        default:
            break;
    }
}

void keyboardUp(unsigned char key, int x, int y) {
    application->KeyOff(key);
}

void special(int key, int x, int y) {
    application->KeyOn(key + 1000);
}

void specialUp(int key, int x, int y) {
    application->KeyOff(key + 1000);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glewInit();
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(150, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Space Invaders");
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    application = new Application();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(special);
    glutSpecialUpFunc(specialUp);
    glutIdleFunc(idle);
    glutMainLoop();
    delete application;

    return 0;
}
