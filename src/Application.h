#ifndef SPACEINVADERS_APPLICATION_H
#define SPACEINVADERS_APPLICATION_H

#include <Registry/GameRegistry.h>
#include <Registry/InputRegistry.h>
#include <SceneBuilder/ISceneBuilder.h>
#include <Game/Object/Rectangle.h>
#include <Game/Object/SpaceShip.h>
#include <Game/Object/SpaceInvader.h>
#include <Game/Object/SpaceShipShot.h>
#include <Game/Object/SpaceShipSpecialShot.h>
#include <Game/Object/SpaceInvaderShot.h>
#include <Game/Object/Item.h>
#include <Game/Object/SpaceShipSpecialShot.h>
#include <Game/Object/SpaceInvaderShot.h>
#include <Game/Background/Background.h>

class Application {
public:
    Application();

    void OnDisplay() const;

    void OnDisplayInterface() const;

    void OnDisplayBackground() const;

    void OnIdle(float);

    void KeyOn(int id) const;

    void KeyOff(int id) const;

private:
    ISceneBuilder *sceneBuilder;
    GameRegistry<Rectangle> *rectangleRegistry;
    GameRegistry<SpaceShip> *spaceShipRegistry;
    GameRegistry<SpaceInvader> *spaceInvaderRegistry;
    GameRegistry<SpaceShipShot> *spaceShipShotRegistry;
    GameRegistry<SpaceShipSpecialShot> *spaceShipSpecialShotRegistry;
    GameRegistry<SpaceInvaderShot> *spaceInvaderShotRegistry;
    GameRegistry<Item> *itemRegistry;
    GameRegistry<IBackground> *backgroundRegistry;
    InputRegistry *inputRegistry;
};

#endif //SPACEINVADERS_APPLICATION_H
