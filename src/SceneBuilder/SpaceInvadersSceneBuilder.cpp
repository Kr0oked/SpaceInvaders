#include <Registry/ObjectRegistry.h>
#include <Object/Rectangle/Rectangle.h>
#include <Object/Rectangle/SpaceShip.h>
#include <Object/Rectangle/SpaceInvader.h>
#include <Object/Rectangle/Item.h>
#include <Object/Rectangle/SpaceInvaderShot.h>
#include <Object/Rectangle/SpaceShipShot.h>
#include <Object/Rectangle/SpaceShipSpecialShot.h>
#include "SpaceInvadersSceneBuilder.h"

void SpaceInvadersSceneBuilder::BuildScene() {
    SpaceShip* spaceShip = new SpaceShip();
    spaceShip->SetPosition(glm::vec2(0.0f, -0.7f));
    spaceShip->SetWidth(0.06f);
    spaceShip->SetHeight(0.03f);
    ObjectRegistry<SpaceShip>::Instance()->Register(spaceShip);

    float size;
    int row = 1;
    for (float y = 0; y <= 0.9f; y += 0.15f)
    {
        size = 0.1f - row * 0.01f;
        for (float x = -0.9f; x <= 0.9f; x += 0.15f)
        {
            int lives = 8 - row;
            SpaceInvader* spaceInvader = new SpaceInvader();
            spaceInvader->SetPosition(glm::vec2(x, y));
            spaceInvader->SetWidth(size);
            spaceInvader->SetHeight(size);
            spaceInvader->SetLives(lives);
            ObjectRegistry<SpaceInvader>::Instance()->Register(spaceInvader);
        }
        row++;
    }

    Rectangle* bar = new Rectangle();
    bar->SetPosition(glm::vec2(0, -0.8f));
    bar->SetWidth(2.0f);
    bar->SetHeight(0.01f);
    ObjectRegistry<Rectangle>::Instance()->Register(bar);
}

void SpaceInvadersSceneBuilder::ResetScene() {
    ObjectRegistry<Item>::Instance()->UnregisterAll();
    ObjectRegistry<Rectangle>::Instance()->UnregisterAll();
    ObjectRegistry<SpaceInvader>::Instance()->UnregisterAll();
    ObjectRegistry<SpaceInvaderShot>::Instance()->UnregisterAll();
    ObjectRegistry<SpaceShip>::Instance()->UnregisterAll();
    ObjectRegistry<SpaceShipShot>::Instance()->UnregisterAll();
    ObjectRegistry<SpaceShipSpecialShot>::Instance()->UnregisterAll();
    BuildScene();
}
