#include "ShinyMaterial.h"
#include "../../utils/utils.h"

ShinyMaterial::ShinyMaterial(ShaderType type, const char *shaderName, GLfloat shininess, const glm::vec3 &emission)
: BasicMaterial(type, shaderName) {
    setShininess(shininess);
    setEmission(emission);
}

void ShinyMaterial::setShininess(GLfloat targetShininess) {
    if(targetShininess < MIN_SHININESS || targetShininess > MAX_SHININESS) {
        return;
    }
    shininess = targetShininess * SHININESS_COEFFICIENT;
}

void ShinyMaterial::setEmission(const glm::vec3 &targetEmission) {
    emission = rgb_to_normalized(targetEmission);
}

bool ShinyMaterial::apply() {
    if(BasicMaterial::apply()) {
        shader->setVec3("material.emission", emission);
        shader->setFloat("material.shininess", shininess);
        return true;
    }
    return false;
}
