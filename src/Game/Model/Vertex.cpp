#include "Vertex.h"

Vertex::Vertex(const glm::vec3 &position, const glm::vec3 &normal, const glm::vec2 &texCoords)
: position{position}, normal{normal}, texCoords{texCoords} {

}

void Vertex::copyVector(glm::vec3 &dest, const aiVector3D &src) {
    dest.x = src.x;
    dest.y = src.y;
    dest.z = src.z;
}

void Vertex::copyVector(glm::vec2 &dest, const aiVector3D &src) {
    dest.x = src.x;
    dest.y = src.y;
}

void Vertex::setPosition(const aiVector3D &pos) {
    copyVector(position, pos);
}

void Vertex::setNormal(const aiVector3D &norm) {
    copyVector(normal, norm);
}

void Vertex::setTexCoords(const aiVector3D &coords) {
    copyVector(texCoords, coords);
}
