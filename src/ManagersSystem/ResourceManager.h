#pragma once

#include "IGameManager.h"
#include "../Game/Texture/Texture2D.h"
#include "../utils/utils.h"

class ResourceManager : public IGameManager {
private:
    const char *defaultTexturePath;
    Texture2D *defaultTexture;
public:
    void startUp() override;
    NODISCARD GLuint getDefaultTexture() const;
};