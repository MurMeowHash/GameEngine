#pragma once

#include "IGameManager.h"
#include "../Shader/Shader.h"
#include "../Shader/ShaderType.h"
#include <unordered_map>

class ShaderManager : public IGameManager {
private:
    std::pair<const char *, const char *> colorShaderPaths;
    std::pair<const char *, const char *> textureShaderPaths;
    std::unordered_map<ShaderType, std::pair<const char *, const char *>> shaderPaths;
    std::unordered_map<ShaderType, Shader> shaders;
public:
    void startUp() override;
    void loadShader(ShaderType type);
    Shader getShader(ShaderType type) const;
};