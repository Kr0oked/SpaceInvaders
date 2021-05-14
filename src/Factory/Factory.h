#ifndef SPACEINVADERS_IFACTORY_H
#define SPACEINVADERS_IFACTORY_H

#include <string>
#include <type_traits>
#include <Game/IObject.h>
#include <Game/Object/Rectangle.h>
#include <Game/Object/SpaceInvader.h>
#include <SceneBuilder/ISceneBuilder.h>
#include <SceneBuilder/SpaceInvadersSceneBuilder.h>
#include <TextureLoader/ITextureLoader.h>
#include <TextureLoader/TextureLoader.h>
#include <Game/Object/Item.h>
#include <Game/Object/SpaceInvaderShot.h>
#include <Game/Object/SpaceShipShot.h>
#include <Game/Object/SpaceShip.h>

template<class T>
class Factory {
public:
    virtual T *Create(std::string className) {
        if (std::is_base_of<ISceneBuilder, T>::value) {
            if (className == "SpaceInvadersSceneBuilder") {
                return (T *) new SpaceInvadersSceneBuilder();
            }
        }

        return 0;
    }
};

#endif //SPACEINVADERS_IFACTORY_H
