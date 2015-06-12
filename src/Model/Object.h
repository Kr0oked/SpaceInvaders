#ifndef SPACEINVADERS_OBJECT_H
#define SPACEINVADERS_OBJECT_H

#include <vector>
#include <tinyobjloader/tiny_obj_loader.h>

typedef struct {
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
} object;

#endif //SPACEINVADERS_OBJECT_H
