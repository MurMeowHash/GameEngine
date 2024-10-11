#include "LightMaterial.h"

LightMaterial::LightMaterial(const glm::vec3 &color)
: BasicMaterial(ShaderType::LightShader, "LIGHT_SHADER") {

}

void LightMaterial::setColor(const glm::vec3 &targetColor) {
    color = rgb_to_normalized(targetColor);
}

bool LightMaterial::apply() {
    if(BasicMaterial::apply()) {
        shader->setVec3("color", color);
        return true;
    }
    return false;
}
