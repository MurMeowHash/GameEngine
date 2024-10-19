#include "BasicMaterial.h"
#include "../../ManagersSystem/Managers.h"
#include "../../Debug/Debug.h"

BasicMaterial::BasicMaterial(ShaderType type, const char *shaderName) : initialized(false) {
    initShader(type, shaderName);
}

void BasicMaterial::initShader(ShaderType type, const char *shaderName) {
    shader = Managers::getShaderManager()->getShader(type);
    if(!shader) {
        Debug::logError("MATERIAL", "UNABLE_TO_FIND_SHADER", shaderName);
        return;
    }
    initialized = true;
}

bool BasicMaterial::good() const {
    return initialized;
}

bool BasicMaterial::apply() {
    if(shader) {
        return true;
    } else {
        Managers::getResourceManager()->getDefaultMaterial()->apply();
        return false;
    }
}

BasicMaterial::operator bool() const {
    return good();
}

bool BasicMaterial::operator!() const {
    return !good();
}

Shader *BasicMaterial::getShader() const {
    return shader;
}