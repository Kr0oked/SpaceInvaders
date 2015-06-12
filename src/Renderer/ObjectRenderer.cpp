#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <Model/Object.h>
#include "ObjectRenderer.h"

void ObjectRenderer::Render(const object* obj) {
    glBegin(GL_TRIANGLES);

    for (size_t i = 0; i < obj->shapes.size(); ++i) {
        tinyobj::mesh_t m = obj->shapes[i].mesh;

        std::vector<glm::vec3> positions;
        for (size_t j = 0; j < m.positions.size(); j += 3) {
            positions.push_back(glm::vec3(m.positions[j], m.positions[j + 1], m.positions[j + 2]));
        }

        std::vector<glm::vec3> normals;
        for (size_t j = 0; j < m.normals.size(); j += 3) {
            normals.push_back(glm::vec3(m.normals[j], m.normals[j + 1], m.normals[j + 2]));
        }

        for (size_t k = 0; k < m.indices.size(); k += 3) {
            for (size_t j = 0; j < 3; ++j) {
                const glm::vec3 &vertex = positions[m.indices[k + j]];
                const glm::vec3 &normal = normals[m.indices[k + j]];
                glNormal3fv(&normal[0]);
                glVertex3fv(&vertex[0]);
            }
        }
    }

    glEnd();
}