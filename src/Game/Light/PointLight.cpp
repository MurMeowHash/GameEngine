#include "PointLight.h"

PointLight::PointLight(GLfloat radius, const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular,
                       const glm::vec3 &position, const glm::vec3 &rotation) : Light("pointLight", currentIndex,
                                                                                     ambient, diffuse, specular, position,
                                                                                     rotation) {
    setRadius(radius);
}

void PointLight::setRadius(GLfloat targetRadius) {
    if(targetRadius < MIN_RADIUS || targetRadius > MAX_RADIUS) {
        return;
    }
    radius = targetRadius;
}

void PointLight::updateTransform() {
    GameObject::updateTransform();
    constant = 1.0f;
    linear = LINEAR_MULTIPLIER / radius;
    quadratic = QUADRATIC_MULTIPLIER / (radius * radius);
}

bool PointLight::set(Shader *shader) {
    if(Light::set(shader)) {
        shader->setVec3((lightName + ".position").c_str(), position);
        shader->setFloat((lightName + ".constant").c_str(), constant);
        shader->setFloat((lightName + ".linear").c_str(), linear);
        shader->setFloat((lightName + ".quadratic").c_str(), quadratic);
        return true;
    }
    return false;
}
