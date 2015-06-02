#include <Factory/Factory.h>
#include <Registry/ObjectRegistry.h>
#include "SpaceShipSpecialShot.h"

SpaceInvader::SpaceInvader() : Rectangle(), lives(1), lastAction(0.0f) {
    Factory<ITextureLoader> textureFactory = Factory<ITextureLoader>();
    ITextureLoader* textureLoader = textureFactory.Create("TextureLoader");
    tex1 = textureLoader->Load("data/img/SpaceInvader1.png");
    tex2 = textureLoader->Load("data/img/SpaceInvader2.png");
    SetSurface(tex1);
    texCurrent = tex1;
}

bool SpaceInvader::Idle(float elapsedTime) {
    if (elapsedTime - lastAction > 1.5f)
    {
        lastAction = elapsedTime;
        ChangeTexture();
    }

    ObjectRegistry<SpaceShipShot>* shotRegistry = ObjectRegistry<SpaceShipShot>::Instance();
    for (ObjectRegistry<SpaceShipShot>::iterator it = shotRegistry->Begin(); it != shotRegistry->End(); ++it) {
        if ((*it)->Intersect(this)) {
            SetLives((*it)->Hit(GetLives()));
            break;
        }
    }

    ObjectRegistry<SpaceShipSpecialShot>* spShotRegistry = ObjectRegistry<SpaceShipSpecialShot>::Instance();
    for (ObjectRegistry<SpaceShipSpecialShot>::iterator it = spShotRegistry->Begin(); it != spShotRegistry->End(); ++it) {
        if ((*it)->Intersect(this)) {
            SetLives((*it)->Hit(GetLives()));
            break;
        }
    }

    if (GetLives() <= 0) {
        if (rand() % 3 == 0) {
            Item* item = new Item(GetPosition());
            ObjectRegistry<Item>::Instance()->Register(item);
        }
        return true;
    }

    if ((int)elapsedTime % 2 == 0 && rand() % 200 == 0)
    {
        Shoot();
    }

    Rectangle::Idle(elapsedTime);
    return false;
}

int SpaceInvader::GetLives() const {
    return lives;
}

void SpaceInvader::SetLives(int lives_) {
    lives = lives_;
}

void SpaceInvader::Shoot() const {
    SpaceInvaderShot* shot = new SpaceInvaderShot(GetPosition());
    ObjectRegistry<SpaceInvaderShot>::Instance()->Register(shot);
}

void SpaceInvader::ChangeTexture() {
    if (texCurrent == tex1) {
        texCurrent = tex2;
    }
    else {
        texCurrent = tex1;
    }
    SetSurface(texCurrent);
}