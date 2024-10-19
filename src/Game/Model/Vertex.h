#pragma once

#include <glm/glm.hpp>
#include <assimp/vector3.h>
#include <assimp/vector2.h>
#include "../../utils/utils.h"

struct Vertex {
    static constexpr glm::vec3 DEFAULT_VERTEX_DATA{0.0f};
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
    static void copyVector(glm::vec3 &dest, const aiVector3D &src);
    static void copyVector(glm::vec2 &dest, const aiVector3D &src);
    explicit Vertex(const glm::vec3 &position = DEFAULT_VERTEX_DATA, const glm::vec3 &normal = DEFAULT_VERTEX_DATA,
           const glm::vec2 &texCoords = DEFAULT_VERTEX_DATA);
    void setPosition(const aiVector3D &pos);
    void setNormal(const aiVector3D &norm);
    void setTexCoords(const aiVector3D &coords);
};