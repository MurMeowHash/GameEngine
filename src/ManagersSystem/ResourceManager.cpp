#include "ResourceManager.h"
#include "../Debug/Debug.h"

void ResourceManager::startUp() {
    logManagerLoading("Resource");
    defaultTexturePath = "../global_textures/default_texture.png";
    defaultTexture = new Texture2D{defaultTexturePath};
    loadedTextures.emplace(defaultTexturePath, defaultTexture);
    state = ManagerState::Started;
}

Texture2D *ResourceManager::getDefaultTexture() const {
    return defaultTexture;
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
}
