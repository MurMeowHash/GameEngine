#pragma once

#include "ShaderManager.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include <array>

class Managers {
private:
    static ShaderManager *shaderManager;
    static ResourceManager *resourceManager;
    static GameManager *gameManager;
    static std::array<IGameManager *, 3> managers;
    static void initialize();
public:
    static ShaderManager *getShaderManager();
    static ResourceManager *getResourceManager();
    static GameManager *getGameManager();
    static void startManagers();
    static void terminate();
};