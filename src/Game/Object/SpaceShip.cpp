#include <GL/glew.h>
#include <Factory/Factory.h>
#include <Registry/InputRegistry.h>
#include <Registry/GameRegistry.h>
#include <Registry/ObjectRegistry.h>
#include <Renderer/ObjectRenderer.h>
#include <Camera/SceneCamera.h>
#include "SpaceShipSpecialShot.h"

SpaceShip::SpaceShip() : Rectangle(), lastShot(0.0f), specialShot(false), lives(5), immune(0.0f), rotation(0.0f) {
    TextureLoader* textureLoader = TextureLoader::Instance();
    texLive = textureLoader->Load("data/img/heart.png");
    SetSurface(1.0f, 1.0f, 1.0f, 1.0f);
    SetWidth(0.06f);
    SetHeight(0.03f);
    SetDepth(0.03f);
}

bool SpaceShip::Idle(float elapsedTime) {
    if (GetLastTime() == 0.0f)
    {
        Rectangle::Idle(elapsedTime);
    }

    float deltaTime = elapsedTime - GetLastTime();

    InputRegistry* inputRegistry = InputRegistry::Instance();

    if (inputRegistry->IsKeyRegistered(KEY_LEFT)) {
        MoveLeft(deltaTime);
        rotation += -90.0f * deltaTime, -45.0f, 45.0f;
        rotation = glm::clamp(rotation, -45.0f, 45.0f);
    }
    else if (inputRegistry->IsKeyRegistered(KEY_RIGHT)) {
        MoveRight(deltaTime);
        rotation += 90.0f * deltaTime, -45.0f, 45.0f;
        rotation = glm::clamp(rotation, -45.0f, 45.0f);
    }
    else {
        if (rotation < 0.0f) {
            rotation += 120.0f * deltaTime, -45.0f, 45.0f;
            rotation = glm::clamp(rotation, -45.0f, 0.0f);
        }
        else {
            rotation += -120.0f * deltaTime;
            rotation = glm::clamp(rotation, 0.0f, 45.0f);
        }
    }

    if (inputRegistry->IsKeyRegistered(KEY_SPACEBAR)) {
        if (elapsedTime - lastShot > 1.0f) {
            lastShot = elapsedTime;
            Shoot();
        }
    }

    if (inputRegistry->IsKeyRegistered(KEY_UP) && specialShot) {
        specialShot = false;
        ShootSpecial();
    }

    if (immune == 0.0f) {
        GameRegistry<SpaceInvaderShot>* shotRegistry = GameRegistry<SpaceInvaderShot>::Instance();
        for (GameRegistry<SpaceInvaderShot>::iterator it = shotRegistry->Begin(); it != shotRegistry->End(); ++it) {
            if ((*it)->Intersect(this)) {
                SetLives((*it)->Hit(GetLives()));
                immune = elapsedTime;
                SetSurface(1.0f, 1.0f, 1.0f, 0.1f);
                break;
            }
        }
    }
    else {
        if (elapsedTime - immune > 2) {
            immune = 0.0f;
            SetSurface(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }

    if (GetLives() <= 0) {
        return true;
    }

    GameRegistry<Item>* itemRegistry = GameRegistry<Item>::Instance();
    for (GameRegistry<Item>::iterator it = itemRegistry->Begin(); it != itemRegistry->End(); ++it) {
        if ((*it)->Intersect(this)) {
            (*it)->Activate();
            specialShot = true;
            break;
        }
    }

    Rectangle::Idle(elapsedTime);
    return false;
}

void SpaceShip::Draw() const {
    object* obj = ObjectRegistry::Instance()->GetObject("SpaceShip");
    ObjectRenderer objectRenderer;

    glPushMatrix();
    glTranslatef(GetPosition().x, GetPosition().y, 0.0f);;
    glScalef(0.01f, 0.01f, 0.01f);
    glRotatef(rotation, 0.0f, 1.0f, 0.0f);
    glEnable(GL_COLOR_MATERIAL);
    glColor4f(GetRed(), GetBlue(), GetGreen(), GetAlpha());

    objectRenderer.Render(obj);

    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
}

int SpaceShip::GetLives() const {
    return lives;
}

void SpaceShip::SetLives(int lives_) {
    lives = lives_;
}

void SpaceShip::SetPosition(glm::vec2 position) {
    SceneCamera* sceneCamera = (*GameRegistry<SceneCamera>::Instance()->Begin());
    sceneCamera->setEye(glm::vec3(position.x, position.y - 0.3, 0.1));
    sceneCamera->setCenter(glm::vec3(position, 0.0));

    Rectangle::SetPosition(position);
}

void SpaceShip::DrawInterface() {
    float w = 0.1f;
    float x = -1.0f + w;
    float y = -1.0f + w;
    for (int i = 0; i < lives; i++) {
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texLive);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + w, 0.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, 0.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(x + w, y, 0.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(x + w, y + w, 0.0f);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        x += w * 2;
    }

    x = 1.0f - w;
    y = -1.0f + w;
    if (specialShot) {
        glEnable(GL_COLOR_MATERIAL);
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glBegin(GL_QUADS);
            glVertex3f(x, y + w, 0.0f);
            glVertex3f(x, y, 0.0f);
            glVertex3f(x - w, y, 0.0f);
            glVertex3f(x - w, y + w, 0.0f);
        glEnd();
        glDisable(GL_COLOR_MATERIAL);
    }
}

void SpaceShip::MoveLeft(float deltaTime) {
    Move(glm::vec2(-0.5f, 0) * deltaTime);
}

void SpaceShip::MoveRight(float deltaTime) {
    Move(glm::vec2(0.5f, 0) * deltaTime);
}

void SpaceShip::Shoot() {
    SpaceShipShot* shot = new SpaceShipShot(GetPosition());
    GameRegistry<SpaceShipShot>::Instance()->Register(shot);
}

void SpaceShip::ShootSpecial() {
    SpaceShipSpecialShot* spaceShipSpecialShot = new SpaceShipSpecialShot(GetPosition());
    GameRegistry<SpaceShipSpecialShot>::Instance()->Register(spaceShipSpecialShot);
}
