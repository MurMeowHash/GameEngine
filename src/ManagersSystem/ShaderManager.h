#pragma once

#include "AbstractManager.h"
#include "../Shader/Shader.h"
#include "../Shader/ShaderType.h"
#include <unordered_map>
#include "../Dispose/IDisposable.h"
#include "ManagerState.h"

class ShaderManager : public AbstractManager, public IDisposable {
private:
    std::pair<const char *, const char *> colorShaderPaths;
    std::pair<const char *, const char *> textureShaderPaths;
    std::unordered_map<ShaderType, std::pair<const char *, const char *>> shaderPaths;
    std::unordered_map<ShaderType, Shader> shaders;
public:
    void startUp() override;
    void loadShader(ShaderType type);
    Shader getShader(ShaderType type) const;
    void dispose() override;
};