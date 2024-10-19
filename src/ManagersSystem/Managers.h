#pragma once

#include "ShaderManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include <array>

class Managers {
private:
    static bool managersInitialized;
    static ShaderManager *shaderManager;
    static ResourceManager *resourceManager;
    static SceneManager *sceneManager;
    static std::array<AbstractManager *, 3> managers;
    static std::array<IDisposable *, 2> disposableManagers;
    static void initialize();
public:
    static ShaderManager* getShaderManager();
    static ResourceManager* getResourceManager();
    static SceneManager* getSceneManager();
    static void startManagers();
    static void shut();
};