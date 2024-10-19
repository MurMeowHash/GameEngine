#include "Scene.h"

void Scene::applyLight(Shader *shader) {

}

const char *Scene::getName() const {
    return name;
}

Camera *Scene::getActiveCamera() const {
    return activeCamera;
}
