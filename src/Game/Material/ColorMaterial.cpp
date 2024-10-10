#include "ColorMaterial.h"

ColorMaterial::ColorMaterial(const glm::vec3 &diffuse, const glm::vec3 &specular, GLfloat shininess, const glm::vec3 &emission)
: ShinyMaterial(ShaderType::ColorShader, "COLOR_SHADER", shininess, emission) {
    setDiffuse(diffuse);
    setSpecular(specular);
}

void ColorMaterial::setDiffuse(const glm::vec3 &diffuseColor) {
    diffuse = rgb_to_normalized(diffuseColor);
}

void ColorMaterial::setSpecular(const glm::vec3 &specularColor) {
    specular = rgb_to_normalized(specularColor);
}

bool ColorMaterial::apply() {
    if(ShinyMaterial::apply()) {
        shader->setVec3("material.diffuse", diffuse);
        shader->setVec3("material.specular", specular);
        return true;
    }
    return false;
}