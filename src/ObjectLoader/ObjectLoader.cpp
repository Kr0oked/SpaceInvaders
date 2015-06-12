#include <iostream>
#include <assert.h>
#include "ObjectLoader.h"

object* ObjectLoader::Load(const std::string& filename, const std::string& materialPath){
    object* obj = new object;

    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string err = tinyobj::LoadObj(shapes, materials, filename.c_str(), materialPath.c_str());

    if (!err.empty()) {
        std::cerr << err << std::endl;
        exit(1);
    }

    obj->shapes = shapes;
    obj->materials = materials;

    for (size_t i = 0; i < shapes.size(); i++) {
        printf("shape[%ld].name = %s\n", i, shapes[i].name.c_str());
        printf("Size of shape[%ld].indices: %ld\n", i, shapes[i].mesh.indices.size());
        printf("Size of shape[%ld].material_ids: %ld\n", i, shapes[i].mesh.material_ids.size());
        assert((shapes[i].mesh.indices.size() % 3) == 0);
        for (size_t f = 0; f < shapes[i].mesh.indices.size() / 3; f++) {
            printf("  idx[%ld] = %d, %d, %d. mat_id = %d\n",
                   f,
                   shapes[i].mesh.indices[3*f+0],
                   shapes[i].mesh.indices[3*f+1],
                   shapes[i].mesh.indices[3*f+2],
                   shapes[i].mesh.material_ids[f]);
        }

        printf("shape[%ld].vertices: %ld\n", i, shapes[i].mesh.positions.size());
        assert((shapes[i].mesh.positions.size() % 3) == 0);
        for (size_t v = 0; v < shapes[i].mesh.positions.size() / 3; v++) {
            printf("  v[%ld] = (%f, %f, %f)\n", v,
                   shapes[i].mesh.positions[3*v+0],
                   shapes[i].mesh.positions[3*v+1],
                   shapes[i].mesh.positions[3*v+2]);
        }
    }

    return obj;
}