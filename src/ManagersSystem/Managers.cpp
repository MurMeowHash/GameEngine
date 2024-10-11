#include "Managers.h"
#include "../Debug/Debug.h"
#include "../Error/Error.h"

bool Managers::managersInitialized{false};

ShaderManager *Managers::shaderManager;
ResourceManager *Managers::resourceManager;
std::array<AbstractManager *, 2> Managers::managers;
std::array<IDisposable *, 2> Managers::disposableManagers;

void Managers::initialize() {
    shaderManager = new ShaderManager;
    managers[0] = shaderManager;
    disposableManagers[0] = shaderManager;
    resourceManager = new ResourceManager;
    managers[1] = resourceManager;
    disposableManagers[1] = resourceManager;
}

void Managers::startManagers() {
    initialize();
    managersInitialized = true;
    GLuint countLoadedManagers{0};
    for(AbstractManager *manager : managers) {
        manager->startUp();
        if(manager->getState() == ManagerState::Started) {
            countLoadedManagers++;
        }
    }
    Debug::log(std::to_string(countLoadedManagers) + "/" + std::to_string(managers.size()) + " managers have started up");
    if(countLoadedManagers != managers.size()) {
        Error::fallWithMessage("MANAGERS", "SOME_MANAGERS_FAILED_TO_START");
    }
}

ShaderManager *Managers::getShaderManager() {
    return shaderManager;
}

ResourceManager *Managers::getResourceManager() {
    return resourceManager;
}

void Managers::shut() {
    if(!managersInitialized) {
        Debug::logError("MANAGERS", "UNABLE_TO_SHUT");
        return;
    }
    for(IDisposable *&manager : disposableManagers) {
        manager->dispose();
        delete manager;
    }
}