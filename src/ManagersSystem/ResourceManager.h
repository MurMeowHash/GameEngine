#pragma once

#include "AbstractManager.h"
#include "../Game/Texture/Texture2D.h"
#include "../Game/Material/ColorMaterial.h"
#include "../utils/utils.h"
#include <unordered_map>
#include "../Dispose/IDisposable.h"

class ResourceManager : public AbstractManager, public IDisposable {
private:
    const char *defaultTexturePath;
    Texture2D *defaultTexture;
    ColorMaterial *defaultMaterial;
    std::unordered_map<const char *, Texture2D *> loadedTextures;
public:
    explicit ResourceManager();
    void startUp() override;
    Texture2D *getDefaultTexture() const;
    ColorMaterial *getDefaultMaterial() const;
    Texture2D *findTexture(const char *path);
    void addTexture(Texture2D *texture);
    void dispose() override;
};