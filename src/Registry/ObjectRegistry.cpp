#include <ObjectLoader/ObjectLoader.h>
#include "ObjectRegistry.h"

const std::string OBJECT_PATH = "data/obj/";
const std::string MATERIAL_PATH = "data/obj";

ObjectRegistry* ObjectRegistry::instance = 0;

ObjectRegistry* ObjectRegistry::Instance() {
    if (!instance) {
        instance = new ObjectRegistry;
    }

    return instance;
}

object* ObjectRegistry::GetObject(const std::string& key) {
    if (mapObject.find(key) == mapObject.end()) {
        ObjectLoader objectLoader;
        mapObject[key] = objectLoader.Load(OBJECT_PATH + key + ".obj", MATERIAL_PATH);
    }

    return mapObject[key];
}
