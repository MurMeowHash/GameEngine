#include "Managers.h"
#include "../Debug/Debug.h"

ShaderManager *Managers::shaderManager;
ResourceManager *Managers::resourceManager;
GameManager *Managers::gameManager;
std::array<IGameManager *, 3> Managers::managers;

void Managers::initialize() {
    shaderManager = new ShaderManager;
    managers[0] = shaderManager;
    resourceManager = new ResourceManager;
    managers[1] = resourceManager;
    gameManager = new GameManager;
    managers[2] = gameManager;
}

void Managers::startManagers() {
    initialize();
    for(IGameManager *manager : managers) {
        manager->startUp();
    }
    Debug::log("Managers has started up");
}

void Managers::terminate() {
    for(IGameManager *manager : managers) {
        delete manager;
    }
}

ShaderManager *Managers::getShaderManager() {
    return shaderManager;
}

ResourceManager *Managers::getResourceManager() {
    return resourceManager;
}

GameManager *Managers::getGameManager() {
    return gameManager;
}
