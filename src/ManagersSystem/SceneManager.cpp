#include "SceneManager.h"
#include "../Debug/Debug.h"

void SceneManager::startUp() {
    logManagerLoading("Scene");
    activeScene = nullptr;
    state = ManagerState::Started;
}

void SceneManager::setActiveScene(const char *sceneName) {
    auto targetScene = scenes.find(sceneName);
    if(targetScene == scenes.end()) {
        Debug::logError("SCENE", "SUCH_SCENE_DOES_NOT_EXIST", sceneName);
        return;
    }
    activeScene = targetScene->second;
}

void SceneManager::addScene(Scene *scene) {
    if(scene == nullptr) {
        Debug::logError("SCENE", "CAN_NOT_BE_NULL");
        return;
    }
    auto targetScene = scenes.emplace(scene->getName(), scene);
    if(!targetScene.second) {
        Debug::logError("SCENE", "SUCH_SCENE_ALREADY_EXISTS", scene->getName());
    }
}

Scene *SceneManager::getActiveScene() const {
    return activeScene;
}
