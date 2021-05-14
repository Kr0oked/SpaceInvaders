#include <GL/glew.h>
#include <Factory/Factory.h>
#include <Registry/GameRegistry.h>
#include <Registry/ObjectRegistry.h>
#include <Renderer/ObjectRenderer.h>
#include "SpaceShipSpecialShot.h"

SpaceInvader::SpaceInvader() : Rectangle(), lives(1) {
    SetSurface(0.0f, 1.0f, 0.0f, 1.0f);
    SetWidth(0.11f);
    SetHeight(0.02f);
    SetDepth(0.07f);
}

bool SpaceInvader::Idle(float elapsedTime) {
    GameRegistry<SpaceShipShot> *shotRegistry = GameRegistry<SpaceShipShot>::Instance();
    for (auto it = shotRegistry->Begin(); it != shotRegistry->End(); ++it) {
        if ((*it)->Intersect(this)) {
            SetLives((*it)->Hit(GetLives()));
            break;
        }
    }

    GameRegistry<SpaceShipSpecialShot> *spShotRegistry = GameRegistry<SpaceShipSpecialShot>::Instance();
    for (auto it = spShotRegistry->Begin(); it != spShotRegistry->End(); ++it) {
        if ((*it)->Intersect(this)) {
            SetLives((*it)->Hit(GetLives()));
            break;
        }
    }

    if (GetLives() <= 0) {
        if (rand() % 3 == 0) {
            Item *item = new Item(GetPosition());
            GameRegistry<Item>::Instance()->Register(item);
        }
        return true;
    }

    if ((int) elapsedTime % 2 == 0 && rand() % 200 == 0) {
        Shoot();
    }

    Rectangle::Idle(elapsedTime);
    return false;
}

void SpaceInvader::Draw() const {
    object *obj = ObjectRegistry::Instance()->GetObject("SpaceInvader");

    glPushMatrix();
    glTranslatef(GetPosition().x, GetPosition().y, 0.0f);
    glScalef(0.01f, 0.01f, 0.01f);
    glEnable(GL_COLOR_MATERIAL);
    glColor4f(GetRed(), GetGreen(), GetBlue(), GetAlpha());

    ObjectRenderer::Render(obj);

    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
}

int SpaceInvader::GetLives() const {
    return lives;
}

void SpaceInvader::SetLives(int lives_) {
    lives = lives_;
}

void SpaceInvader::Shoot() const {
    auto *shot = new SpaceInvaderShot(GetPosition());
    GameRegistry<SpaceInvaderShot>::Instance()->Register(shot);
}
