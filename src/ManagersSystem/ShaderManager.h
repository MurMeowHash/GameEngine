#pragma once

#include "IGameManager.h"
#include "../Shader/Shader.h"
#include <unordered_set>
#include "../Shader/ShaderHash.h"

class ShaderManager : public IGameManager {
private:
    std::unordered_set<Shader, ShaderHash> shaders;
public:
    void startUp() override;
};