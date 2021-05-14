#include <GL/glew.h>
#include <GL/glut.h>
#include <ObjectLoader/ObjectLoader.h>
#include <Camera/SceneCamera.h>
#include <Camera/InterfaceCamera.h>
#include "Application.h"

const int ID_ESC = 27;

Application *application = nullptr;
SceneCamera *sceneCamera = nullptr;
InterfaceCamera *interfaceCamera = nullptr;

GLint screenX = 0;
GLint screenY = 0;
GLint screenWidth = 0;
GLint screenHeight = 0;
GLint polygonMode = GL_FILL;

void init() {
    // Camera
    sceneCamera = new SceneCamera(screenWidth, screenHeight, 45.0, 0.1, 100.0);
    sceneCamera->setUp(glm::vec3(0.0, 1.0, 0.0));
    GameRegistry<SceneCamera>::Instance()->Register(sceneCamera);

    interfaceCamera = new InterfaceCamera(-1, 1, -1, 1);

    // Lighting
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_SMOOTH);

    GLfloat matAmbient[] = {0.7, 0.7, 0.7, 0.01};
    GLfloat matDiffuse[] = {0.1, 0.1, 0.1, 0.1};
    GLfloat matSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLint matShininess[] = {128};

    GLfloat lightAmbient[] = {0.1f, 0.1f, 0.1f, 1.0f};
    GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightSpecular[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat lightPosition[] = {0.0f, 30.0f, 60.0f, 0.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialiv(GL_FRONT, GL_SHININESS, matShininess);

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmbient);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_LIGHT0);
    glEnable(GL_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_NORMALIZE);
    glLineWidth(1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(screenX, screenY, screenWidth, screenHeight);

    // Background
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    interfaceCamera->applyProjectionMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    interfaceCamera->applyModelViewMatrix();

    application->OnDisplayBackground();

    // 3D Scene
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    sceneCamera->setScreenWidth(screenWidth);
    sceneCamera->setScreenHeight(screenHeight);
    sceneCamera->applyProjectionMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    sceneCamera->applyModelViewMatrix();

    application->OnDisplay();

    // Interface
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    interfaceCamera->applyProjectionMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    interfaceCamera->applyModelViewMatrix();

    application->OnDisplayInterface();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    /* Scale Viewport to Window Size */
    if (width >= height) {
        screenWidth = height;
        screenHeight = height;
        screenX = int((width - height) / 2 + 0.5);
        screenY = 0;
    } else {
        screenWidth = width;
        screenHeight = width;
        screenX = 0;
        screenY = int((height - width) / 2 + 0.5);
    }
}

void idle() {
    int elapsedTime = glutGet(GLUT_ELAPSED_TIME);
    float sec = (float) elapsedTime / 1000;
    application->OnIdle(sec);
    glutPostWindowRedisplay(1);
}

void keyboard(unsigned char key, __attribute__((unused)) int x, __attribute__((unused)) int y) {
    application->KeyOn(key);
    switch (key) {
        case 'f':
            glutFullScreen();
            break;
        case 'm':
            if (polygonMode == GL_FILL) {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                polygonMode = GL_LINE;
            } else {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                polygonMode = GL_FILL;
            }
            break;
        case ID_ESC:
            exit(0);
        default:
            break;
    }
}

void keyboardUp(unsigned char key, __attribute__((unused)) int x, __attribute__((unused)) int y) {
    application->KeyOff(key);
}

void special(int key, __attribute__((unused)) int x, __attribute__((unused)) int y) {
    application->KeyOn(key + 1000);
}

void specialUp(int key, __attribute__((unused)) int x, __attribute__((unused)) int y) {
    application->KeyOff(key + 1000);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(150, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Space Invaders 3D");

    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }

    init();
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
