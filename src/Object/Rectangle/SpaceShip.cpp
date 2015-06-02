#include <Factory/Factory.h>
#include <Registry/InputRegistry.h>
#include <Registry/ObjectRegistry.h>
#include "SpaceShipSpecialShot.h"

SpaceShip::SpaceShip() : Rectangle(), lastShot(0), specialShot(false), lives(5), immune(0.0f) {
    Factory<ITextureLoader> textureFactory = Factory<ITextureLoader>();
    ITextureLoader* textureLoader = textureFactory.Create("TextureLoader");
    texNormal = textureLoader->Load("data/img/SpaceShip1.png");
    texImmune = textureLoader->Load("data/img/SpaceShip2.png");
    SetSurface(texNormal);

    liveIndicator = new Rectangle(glm::vec2(), 0.06f, 0.03f, texNormal);

    int texItem = textureLoader->Load("data/img/Item.png");
    specialShotIndicator = new Rectangle(glm::vec2(0.9f, -0.9f), 0.03f, 0.03f, texItem);
}

bool SpaceShip::Idle(float elapsedTime) {
    if (GetLastTime() == 0.0f)
    {
        Rectangle::Idle(elapsedTime);
    }

    float deltaTime = elapsedTime - GetLastTime();
    InputRegistry* inputRegistry = InputRegistry::Instance();

    if ((inputRegistry->IsKeyRegistered(KEY_LEFT) ^ inputRegistry->IsKeyRegistered(KEY_RIGHT))) {
        if (inputRegistry->IsKeyRegistered(KEY_LEFT)) {
            MoveLeft(deltaTime);
        }
        else {
            MoveRight(deltaTime);
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
        ObjectRegistry<SpaceInvaderShot>* shotRegistry = ObjectRegistry<SpaceInvaderShot>::Instance();
        for (ObjectRegistry<SpaceInvaderShot>::iterator it = shotRegistry->Begin(); it != shotRegistry->End(); ++it) {
            if ((*it)->Intersect(this)) {
                SetLives((*it)->Hit(GetLives()));
                immune = elapsedTime;
                SetSurface(texImmune);
                break;
            }
        }
    }
    else {
        if (elapsedTime - immune > 2) {
            immune = 0.0f;
            SetSurface(texNormal);
        }
    }

    if (GetLives() <= 0) {
        return true;
    }

    ObjectRegistry<Item>* itemRegistry = ObjectRegistry<Item>::Instance();
    for (ObjectRegistry<Item>::iterator it = itemRegistry->Begin(); it != itemRegistry->End(); ++it) {
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
    float x = -0.9f;
    for (int i = 0; i < lives; i++) {
        liveIndicator->SetPosition(glm::vec2(x, -0.9f));
        liveIndicator->Draw();
        x += 0.15;
    }

    if (specialShot) {
        specialShotIndicator->Draw();
    }

    Rectangle::Draw();
}

int SpaceShip::GetLives() const {
    return lives;
}

void SpaceShip::SetLives(int lives_) {
    lives = lives_;
}

void SpaceShip::MoveLeft(float deltaTime) {
    Move(glm::vec2(-0.5f, 0) * deltaTime);
}

void SpaceShip::MoveRight(float deltaTime) {
    Move(glm::vec2(0.5f, 0) * deltaTime);
}

void SpaceShip::Shoot() {
    SpaceShipShot* shot = new SpaceShipShot(GetPosition());
    ObjectRegistry<SpaceShipShot>::Instance()->Register(shot);
}

void SpaceShip::ShootSpecial() {
    SpaceShipSpecialShot* spaceShipSpecialShot = new SpaceShipSpecialShot(GetPosition());
    ObjectRegistry<SpaceShipSpecialShot>::Instance()->Register(spaceShipSpecialShot);
}
