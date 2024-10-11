#include "ResourceManager.h"
#include "../Debug/Debug.h"

ResourceManager::ResourceManager() : defaultTexture{nullptr}, defaultMaterial{nullptr} {

}

void ResourceManager::startUp() {
    logManagerLoading("Resource");
    defaultTexturePath = "../global_textures/default_texture.png";
    defaultTexture = new Texture2D{defaultTexturePath};
    loadedTextures.emplace(defaultTexturePath, defaultTexture);
    defaultMaterial = new ColorMaterial;
    if(!*defaultMaterial) {
        state = ManagerState::Incomplete;
        Debug::logError("MATERIAL", "DEFAULT_MATERIAL_CAN_NOT_BE_LOADED");
        return;
    }
    state = ManagerState::Started;
}

Texture2D *ResourceManager::getDefaultTexture() const {
    return defaultTexture;
}

ColorMaterial *ResourceManager::getDefaultMaterial() const {
    return defaultMaterial;
}

Texture2D *ResourceManager::findTexture(const char *path) {
    auto targetTexture = loadedTextures.find(path);
    return targetTexture == loadedTextures.end() ? nullptr : targetTexture->second;
}

void ResourceManager::addTexture(const char *path, Texture2D *texture) {
    loadedTextures.emplace(path, texture);
}

void ResourceManager::dispose() {
    if(state == ManagerState::Shutdown) {
        return;
    }
    for(auto &loadedTexture : loadedTextures) {
        loadedTexture.second->dispose();
    }
    delete defaultTexture;
    delete defaultMaterial;
}
