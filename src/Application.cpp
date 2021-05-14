#include <list>
#include <Factory/Factory.h>
#include <Game/Interface/GameOver.h>
#include <Game/Background/Background.h>
#include <Game/Interface/GameWin.h>
#include "Application.h"

Application::Application() {
    rectangleRegistry = GameRegistry<Rectangle>::Instance();
    spaceShipRegistry = GameRegistry<SpaceShip>::Instance();
    spaceInvaderRegistry = GameRegistry<SpaceInvader>::Instance();
    spaceShipShotRegistry = GameRegistry<SpaceShipShot>::Instance();
    spaceShipSpecialShotRegistry = GameRegistry<SpaceShipSpecialShot>::Instance();
    spaceInvaderShotRegistry = GameRegistry<SpaceInvaderShot>::Instance();
    itemRegistry = GameRegistry<Item>::Instance();
    backgroundRegistry = GameRegistry<IBackground>::Instance();
    inputRegistry = InputRegistry::Instance();

    Factory<ISceneBuilder> sceneBuilderFactory = Factory<ISceneBuilder>();
    sceneBuilder = sceneBuilderFactory.Create("SpaceInvadersSceneBuilder");

    sceneBuilder->BuildScene();
}

void Application::OnDisplay() const {
    for (auto it = rectangleRegistry->Begin(); it != rectangleRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (auto it = spaceShipRegistry->Begin(); it != spaceShipRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (auto it = spaceInvaderRegistry->Begin(); it != spaceInvaderRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (auto it = spaceShipShotRegistry->Begin(); it != spaceShipShotRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (auto it = spaceShipSpecialShotRegistry->Begin(); it != spaceShipSpecialShotRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (auto it = spaceInvaderShotRegistry->Begin(); it != spaceInvaderShotRegistry->End(); ++it) {
        (*it)->Draw();
    }

    for (auto it = itemRegistry->Begin(); it != itemRegistry->End(); ++it) {
        (*it)->Draw();
    }
}

void Application::OnDisplayInterface() const {
    IInterface *interface;

    if (spaceInvaderRegistry->Begin() == spaceInvaderRegistry->End()) {
        interface = new GameWin();
    } else if (spaceShipRegistry->Begin() != spaceShipRegistry->End()) {
        interface = (*spaceShipRegistry->Begin());
    } else {
        interface = new GameOver();
    }

    interface->DrawInterface();
}

void Application::OnDisplayBackground() const {
    for (auto it = backgroundRegistry->Begin(); it != backgroundRegistry->End(); ++it) {
        (*it)->DrawBackground();
    }
}

void Application::OnIdle(float elapsedTime) {
    if (inputRegistry->IsKeyRegistered('r')) {
        inputRegistry->UnregisterKey('r');
        sceneBuilder->ResetScene();
    }

    for (auto it = rectangleRegistry->Begin(); it != rectangleRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = rectangleRegistry->Unregister(it);
        } else {
            ++it;
        }
    }

    for (auto it = spaceShipRegistry->Begin(); it != spaceShipRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceShipRegistry->Unregister(it);
        } else {
            ++it;
        }
    }

    for (auto it = spaceInvaderRegistry->Begin(); it != spaceInvaderRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceInvaderRegistry->Unregister(it);
        } else {
            ++it;
        }
    }

    for (auto it = spaceShipShotRegistry->Begin(); it != spaceShipShotRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceShipShotRegistry->Unregister(it);
        } else {
            ++it;
        }
    }

    for (auto it = spaceShipSpecialShotRegistry->Begin(); it != spaceShipSpecialShotRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceShipSpecialShotRegistry->Unregister(it);
        } else {
            ++it;
        }
    }

    for (auto it = spaceInvaderShotRegistry->Begin(); it != spaceInvaderShotRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = spaceInvaderShotRegistry->Unregister(it);
        } else {
            ++it;
        }
    }

    for (auto it = itemRegistry->Begin(); it != itemRegistry->End();) {
        if ((*it)->Idle(elapsedTime)) {
            it = itemRegistry->Unregister(it);
        } else {
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
