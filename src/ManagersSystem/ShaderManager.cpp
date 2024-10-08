#include "ShaderManager.h"
#include "../Debug/Debug.h"
#include "../Error/Error.h"

void ShaderManager::startUp() {
    Debug::log("Shader manager is starting...");
    //TODO: initialize paths
    shaderPaths.emplace(ShaderType::ColorShader, colorShaderPaths);
    shaderPaths.emplace(ShaderType::TextureShader, textureShaderPaths);
}

void ShaderManager::loadShader(ShaderType type) {
    auto foundShader = shaders.find(type);
    if(foundShader != shaders.end()) {
        return;
    }
    auto pathsElement = shaderPaths.find(type);
    if(pathsElement == shaderPaths.end()) {
        Debug::logError("SHADER", "UNABLE_TO_FIND_PATHS");
        return;
    }
    auto targetPaths = pathsElement->second;
    shaders.emplace(type, Shader(targetPaths.first, targetPaths.second));
}

Shader ShaderManager::getShader(ShaderType type) const {
    auto foundShader = shaders.find(type);
    if(foundShader == shaders.end()) {
        Error::fallWithMessage("SHADER", "DOES_NOT_EXIST");
    }
    return std::get<1>(*foundShader);
}