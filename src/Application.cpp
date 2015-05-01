#include <list>
#include <Factory/Factory.h>
#include "Application.h"

Application::Application() {
    rectangleRegistry = ObjectRegistry<Rectangle>::Instance();
    spaceShipRegistry = ObjectRegistry<SpaceShip>::Instance();
    spaceInvaderRegistry = ObjectRegistry<SpaceInvader>::Instance();
    spaceShipShotRegistry = ObjectRegistry<SpaceShipShot>::Instance();
    spaceShipSpecialShotRegistry = ObjectRegistry<SpaceShipSpecialShot>::Instance();
    spaceInvaderShotRegistry = ObjectRegistry<SpaceInvaderShot>::Instance();
    itemRegistry = ObjectRegistry<Item>::Instance();
    inputRegistry = InputRegistry::Instance();

    Factory<ISceneBuilder> sceneBuilderFactory = Factory<ISceneBuilder>();
    sceneBuilder = sceneBuilderFactory.Create("SpaceInvadersSceneBuilder");

    Factory<ITextureLoader> textureLoaderFactory = Factory<ITextureLoader>();
    textureLoader = textureLoaderFactory.Create("TextureLoader");

    sceneBuilder->BuildScene();
}

void Application::OnDisplay() const {
    for (ObjectRegistry<Rectangle>::iterator it = rectangleRegistry->Begin(); it != rectangleRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (ObjectRegistry<SpaceShip>::iterator it = spaceShipRegistry->Begin(); it != spaceShipRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (ObjectRegistry<SpaceInvader>::iterator it = spaceInvaderRegistry->Begin(); it != spaceInvaderRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (ObjectRegistry<SpaceShipShot>::iterator it = spaceShipShotRegistry->Begin(); it != spaceShipShotRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (ObjectRegistry<SpaceShipSpecialShot>::iterator it = spaceShipSpecialShotRegistry->Begin(); it != spaceShipSpecialShotRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (ObjectRegistry<SpaceInvaderShot>::iterator it = spaceInvaderShotRegistry->Begin(); it != spaceInvaderShotRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (ObjectRegistry<Item>::iterator it = itemRegistry->Begin(); it != itemRegistry->End(); ++it) {
        (*it)->Draw();
    }
}

void Application::OnIdle(float elapsedTime) {
    if (inputRegistry->IsKeyRegistered('r')) {
        inputRegistry->UnregisterKey('r');
        sceneBuilder->ResetScene();
    }

    for (ObjectRegistry<Rectangle>::iterator it = rectangleRegistry->Begin(); it != rectangleRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = rectangleRegistry->Unregister(it);
        }
        else {
            ++it;
        }
    }

    for (ObjectRegistry<SpaceShip>::iterator it = spaceShipRegistry->Begin(); it != spaceShipRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceShipRegistry->Unregister(it);
        }
        else {
            ++it;
        }
    }

    for (ObjectRegistry<SpaceInvader>::iterator it = spaceInvaderRegistry->Begin(); it != spaceInvaderRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceInvaderRegistry->Unregister(it);
        }
        else {
            ++it;
        }
    }

    for (ObjectRegistry<SpaceShipShot>::iterator it = spaceShipShotRegistry->Begin(); it != spaceShipShotRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceShipShotRegistry->Unregister(it);
        }
        else {
            ++it;
        }
    }

    for (ObjectRegistry<SpaceShipSpecialShot>::iterator it = spaceShipSpecialShotRegistry->Begin(); it != spaceShipSpecialShotRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceShipSpecialShotRegistry->Unregister(it);
        }
        else {
            ++it;
        }
    }

    for (ObjectRegistry<SpaceInvaderShot>::iterator it = spaceInvaderShotRegistry->Begin(); it != spaceInvaderShotRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceInvaderShotRegistry->Unregister(it);
        }
        else {
            ++it;
        }
    }

    for (ObjectRegistry<Item>::iterator it = itemRegistry->Begin(); it != itemRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = itemRegistry->Unregister(it);
        }
        else {
            ++it;
        }
    }
}

void Application::KeyOn(int id) const {
    inputRegistry->RegisterKey(id);
}

void Application::KeyOff(int id) const {
    inputRegistry->UnregisterKey(id);
}
