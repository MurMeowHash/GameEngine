#pragma once

#include "../../utils/utils.h"
#include "../Camera/Camera.h"
#include "../../Shader/Shader.h"

class Scene {
private:
    const char *name;
    Camera *activeCamera;
public:
    void applyLight(Shader *shader);
    NODISCARD const char* getName() const;
    NODISCARD Camera* getActiveCamera() const;
};