#include "SpotLight.h"

SpotLight::SpotLight(GLfloat innerCutOff, GLfloat outerCutOff, GLfloat radius, const glm::vec3 &ambient,
                     const glm::vec3 &diffuse, const glm::vec3 &specular, const glm::vec3 &position,
                     const glm::vec3 &rotation)
                     : PointLight("spotLights", currentIndex, radius, ambient, diffuse, specular, position, rotation) {
    setInnerCutOff(innerCutOff);
    setOuterCutOff(outerCutOff);
}

void SpotLight::setInnerCutOff(GLfloat cutOff) {
    cutOff = glm::clamp(cutOff, MIN_CUT_OFF, MAX_CUT_OFF);
    innerCutOff = glm::radians(cutOff);
}

void SpotLight::setOuterCutOff(GLfloat cutOff) {
    cutOff = glm::clamp(cutOff, innerCutOff, MAX_CUT_OFF);
    outerCutOff = glm::radians(cutOff);
}

bool SpotLight::set(Shader *shader) {
    if(PointLight::set(shader)) {
        shader->setFloat((lightName + ".innerCutOff").c_str(), innerCutOff);
        shader->setFloat((lightName + ".outerCutOff").c_str(), outerCutOff);
        return true;
    }
    return false;
}
