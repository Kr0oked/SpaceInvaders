#ifndef SPACEINVADERS_TEXT_H
#define SPACEINVADERS_TEXT_H

#include <string>
#include <glm/vec2.hpp>

typedef struct {
    std::string string;
    u_char size;
    glm::vec2 position;
} text;

#endif //SPACEINVADERS_TEXT_H
