#pragma once

#include "AbstractManager.h"
#include "../Game/Scene/Scene.h"
#include "../Shader/Shader.h"
#include <unordered_map>

class SceneManager : public AbstractManager {
private:
    std::unordered_map<const char *, Scene *> scenes;
    Scene *activeScene;
public:
    void startUp() override;
    void setActiveScene(const char *sceneName);
    void addScene(Scene *scene);
    Scene *getActiveScene() const;
};