#include "ShaderManager.h"
#include "../Debug/Debug.h"
#include "../Error/Error.h"

void ShaderManager::startUp() {
    logManagerLoading("Shader");
    //TODO: initialize paths
    shaderPaths.emplace(ShaderType::ColorShader, colorShaderPaths);
    shaderPaths.emplace(ShaderType::TextureShader, textureShaderPaths);
    state = ManagerState::Started;
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
    shaders.emplace(type, new Shader(targetPaths.first, targetPaths.second));
}

Shader *ShaderManager::getShader(ShaderType type) const {
    auto foundShader = shaders.find(type);
    return foundShader == shaders.end() ? nullptr : std::get<1>(*foundShader);
}

void ShaderManager::dispose() {
    if(state == ManagerState::Shutdown) {
        return;
    }
}