#include "Light.h"

Light::Light(std::string lightName, GLuint &currentIndex, const glm::vec3 &ambient, const glm::vec3 &diffuse,
             const glm::vec3 &specular, const glm::vec3 &position, const glm::vec3 &rotation) : ambient{ambient},
             diffuse{diffuse}, specular{specular}, GameObject(position, rotation) {
    init(std::move(lightName), currentIndex);
}

void Light::setAmbient(const glm::vec3 &ambientLight) {
    ambient = rgb_to_normalized(ambientLight);
}

void Light::setDiffuse(const glm::vec3 &diffuseLight) {
    diffuse = rgb_to_normalized(diffuseLight);
}

void Light::setSpecular(const glm::vec3 &specularLight) {
    specular = rgb_to_normalized(specularLight);
}

void Light::init(std::string &&name, GLuint &currentIndex) {
    lightName = name + "[" + std::to_string(currentIndex) + "]";
    currentIndex++;
}

bool Light::set(Shader *shader) {
    if(shader) {
        shader->use();
        shader->setVec3((lightName + ".ambient").c_str(), ambient);
        shader->setVec3((lightName + ".diffuse").c_str(), diffuse);
        shader->setVec3((lightName + ".specular").c_str(), specular);
        return true;
    }
    return false;
}