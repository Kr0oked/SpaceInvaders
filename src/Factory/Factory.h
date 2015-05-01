#ifndef SPACEINVADERS_IFACTORY_H
#define SPACEINVADERS_IFACTORY_H

#include <string>
#include <type_traits>
#include <Object/IObject.h>
#include <Object/Rectangle/Rectangle.h>
#include <Object/Rectangle/SpaceInvader.h>
#include <SceneBuilder/ISceneBuilder.h>
#include <SceneBuilder/SpaceInvadersSceneBuilder.h>
#include <TextureLoader/ITextureLoader.h>
#include <TextureLoader/TextureLoader.h>
#include <Object/Rectangle/Item.h>
#include <Object/Rectangle/SpaceInvaderShot.h>
#include <Object/Rectangle/SpaceShipShot.h>
#include <Object/Rectangle/SpaceShip.h>

template <class T>
class Factory {
public:
    virtual T* Create(std::string className) {
        if (std::is_base_of<ISceneBuilder, T>::value) {
            if (className == "SpaceInvadersSceneBuilder") {
                return (T*)new SpaceInvadersSceneBuilder();
            }
        }
        else if (std::is_base_of<ITextureLoader, T>::value) {
            if (className == "TextureLoader") {
                return (T*)new TextureLoader();
            }
        }

        return 0;
    }
};

#endif //SPACEINVADERS_IFACTORY_H
