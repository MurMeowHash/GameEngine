#include "DirectionalLight.h"

GLuint DirectionalLight::currentIndex{0};

DirectionalLight::DirectionalLight(const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular,
                                   const glm::vec3 &position, const glm::vec3 &rotation)
                                   : Light("directionalLight", currentIndex, ambient, diffuse, specular,
                                           position, rotation) {

}

void DirectionalLight::updateTransform() {
    GameObject::updateTransform();
    rayDirection = glm::normalize(rotationOperand * -Z_AXIS);
}

bool DirectionalLight::set(Shader *shader) {
    if(Light::set(shader)) {
        shader->setVec3((lightName + ".direction").c_str(), rayDirection);
        return true;
    }
    return false;
}
