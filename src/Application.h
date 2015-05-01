#ifndef SPACEINVADERS_APPLICATION_H
#define SPACEINVADERS_APPLICATION_H

#include <SceneBuilder/ISceneBuilder.h>
#include <Object/Rectangle/Rectangle.h>
#include <Object/Rectangle/SpaceShip.h>
#include <Object/Rectangle/SpaceInvader.h>
#include <Object/Rectangle/SpaceShipShot.h>
#include <Object/Rectangle/SpaceShipSpecialShot.h>
#include <Object/Rectangle/SpaceInvaderShot.h>
#include <Object/Rectangle/Item.h>
#include <Registry/InputRegistry.h>
#include <Registry/ObjectRegistry.h>
#include <TextureLoader/ITextureLoader.h>
#include <Object/Rectangle/SpaceShipSpecialShot.h>
#include <Object/Rectangle/SpaceInvaderShot.h>

class Application
{
public:
    Application();
    void OnDisplay() const;
    void OnIdle(float);
    void KeyOn(int id) const;
    void KeyOff(int id) const;

private:
    ISceneBuilder* sceneBuilder;
    ObjectRegistry<Rectangle>* rectangleRegistry;
    ObjectRegistry<SpaceShip>* spaceShipRegistry;
    ObjectRegistry<SpaceInvader>* spaceInvaderRegistry;
    ObjectRegistry<SpaceShipShot>* spaceShipShotRegistry;
    ObjectRegistry<SpaceShipSpecialShot>* spaceShipSpecialShotRegistry;
    ObjectRegistry<SpaceInvaderShot>* spaceInvaderShotRegistry;
    ObjectRegistry<Item>* itemRegistry;
    InputRegistry* inputRegistry;
    ITextureLoader* textureLoader;
};

#endif //SPACEINVADERS_APPLICATION_H
