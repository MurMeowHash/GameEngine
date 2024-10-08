#include "ResourceManager.h"
#include "../Debug/Debug.h"

void ResourceManager::startUp() {
    Debug::log("Resource manager is starting...");
    defaultTexturePath = "../global_textures/default_texture.png";
    defaultTexture = new Texture2D{defaultTexturePath};
}

GLuint ResourceManager::getDefaultTexture() const {
    return defaultTexture->getTextureID();
}
