#pragma once

#include "ShaderManager.h"
#include "ResourceManager.h"
#include <array>

class Managers {
private:
    static bool managersInitialized;
    static ShaderManager *shaderManager;
    static ResourceManager *resourceManager;
    static std::array<AbstractManager *, 2> managers;
    static std::array<IDisposable *, 2> disposableManagers;
    static void initialize();
public:
    static ShaderManager *getShaderManager();
    static ResourceManager *getResourceManager();
    static void startManagers();
    static void shut();
};