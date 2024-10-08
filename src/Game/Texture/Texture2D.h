#pragma once

#include "TextureWrap.h"
#include "TextureFiltration.h"
#include "../../utils/utils.h"

class Texture2D {
private:
    static constexpr const char *DEFAULT_TEXTURE_PATH{"../global_textures/default_texture.png"};
    static constexpr TextureWrap DEFAULT_TEXTURE_WRAP{TextureWrap::Repeat};
    static constexpr TextureFiltration DEFAULT_TEXTURE_FILTRATION{TextureFiltration::TriLinear};
    GLuint textureID;
    GLint width;
    GLint height;
    void createTexture(TextureWrap wrapOption, TextureFiltration filtration);
    void loadTexture(const char *path);
    void setUninitializedTexture();
public:
    explicit Texture2D(const char *texturePath, TextureWrap wrapOption = DEFAULT_TEXTURE_WRAP,
                       TextureFiltration filtration = DEFAULT_TEXTURE_FILTRATION);
    NODISCARD GLuint getTextureID() const;
};