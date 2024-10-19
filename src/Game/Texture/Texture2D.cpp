#include "Texture2D.h"
#include <stb/stb_image.h>
#include "../../Debug/Debug.h"
#include "../../ManagersSystem/Managers.h"

Texture2D::Texture2D(const char *texturePath, TextureWrap wrapOption, TextureFiltration filtration) {
    auto targetTexture = Managers::getResourceManager()->findTexture(texturePath);
    if(targetTexture) {
        *this = *targetTexture;
    } else {
        createTexture(wrapOption, filtration);
        loadTexture(texturePath);
        Managers::getResourceManager()->addTexture(this);
    }
}

void Texture2D::createTexture(TextureWrap wrapOption, TextureFiltration filtration) {
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    auto wrap = static_cast<GLint>(wrapOption);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
    GLint minParam, magParam;
    switch (filtration) {
        case TextureFiltration::Nearest:
            minParam = GL_NEAREST_MIPMAP_NEAREST;
            magParam = GL_NEAREST;
            break;
        case TextureFiltration::BiLinear:
            minParam = GL_LINEAR_MIPMAP_NEAREST;
            magParam = GL_LINEAR;
            break;
        case TextureFiltration::TriLinear:
        default:
            minParam = GL_LINEAR_MIPMAP_LINEAR;
            magParam = GL_LINEAR;
            break;
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minParam);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magParam);
}

void Texture2D::loadTexture(const char *texturePath) {
    GLint numChannels;
    unsigned char *data = stbi_load(texturePath, &width, &height, &numChannels, 0);
    if(!data) {
        Debug::logError("TEXTURE", "INVALID_TEXTURE_PATH", texturePath);
        setUninitializedTexture();
        return;
    }
    path = texturePath;
    GLint format;
    switch (numChannels) {
        case 1:
            format = GL_RED;
            break;
        case 2:
            format = GL_RG;
            break;
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        default:
            Debug::logError("TEXTURE", "UNKNOWN_FORMAT", texturePath);
            format = GL_RGB;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::setUninitializedTexture() {
    glDeleteTextures(1, &textureID);
    *this = *Managers::getResourceManager()->getDefaultTexture(); // TODO: potential null
}

void Texture2D::dispose() {
    glDeleteTextures(1, &textureID);
}

void Texture2D::bind() const {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

const char *Texture2D::getPath() const {
    return path;
}
