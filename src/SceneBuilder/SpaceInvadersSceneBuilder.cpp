#include "Registry/GameRegistry.h"
#include <Game/Object/Rectangle.h>
#include <Game/Object/SpaceShip.h>
#include <Game/Object/SpaceInvader.h>
#include <Game/Object/Item.h>
#include <Game/Object/SpaceInvaderShot.h>
#include <Game/Object/SpaceShipShot.h>
#include <Game/Object/SpaceShipSpecialShot.h>
#include <Game/Background/Background.h>
#include "SpaceInvadersSceneBuilder.h"

void SpaceInvadersSceneBuilder::BuildScene() {
    SpaceShip* spaceShip = new SpaceShip();
    spaceShip->SetPosition(glm::vec2(0.0f, -0.5f));
    GameRegistry<SpaceShip>::Instance()->Register(spaceShip);

    int row = 1;
    for (float y = 0; y <= 1.5f; y += 0.5f)
    {
        int lives = 8 - row;
        for (float x = -0.9f; x <= 0.9f; x += 0.15f)
        {
            SpaceInvader* spaceInvader = new SpaceInvader();
            spaceInvader->SetPosition(glm::vec2(x, y));
            spaceInvader->SetLives(lives);
            GameRegistry<SpaceInvader>::Instance()->Register(spaceInvader);
        }
        row++;
    }

    Background* background = new Background();
    GameRegistry<IBackground>::Instance()->Register(background);
}

void SpaceInvadersSceneBuilder::ResetScene() {
    GameRegistry<Item>::Instance()->UnregisterAll();
    GameRegistry<Rectangle>::Instance()->UnregisterAll();
    GameRegistry<SpaceInvader>::Instance()->UnregisterAll();
    GameRegistry<SpaceInvaderShot>::Instance()->UnregisterAll();
    GameRegistry<SpaceShip>::Instance()->UnregisterAll();
    GameRegistry<SpaceShipShot>::Instance()->UnregisterAll();
    GameRegistry<SpaceShipSpecialShot>::Instance()->UnregisterAll();
    GameRegistry<IBackground>::Instance()->UnregisterAll();
    BuildScene();
}
