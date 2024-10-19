#pragma once

#include "TextureWrap.h"
#include "TextureFiltration.h"
#include "../../utils/utils.h"
#include "../../Dispose/IDisposable.h"

class Texture2D : public IDisposable {
private:
    static constexpr TextureWrap DEFAULT_TEXTURE_WRAP{TextureWrap::Repeat};
    static constexpr TextureFiltration DEFAULT_TEXTURE_FILTRATION{TextureFiltration::TriLinear};
    GLuint textureID;
    GLint width;
    GLint height;
    const char *path;
    void createTexture(TextureWrap wrapOption, TextureFiltration filtration);
    void loadTexture(const char *texturePath);
    void setUninitializedTexture();
public:
    explicit Texture2D(const char *texturePath, TextureWrap wrapOption = DEFAULT_TEXTURE_WRAP,
                       TextureFiltration filtration = DEFAULT_TEXTURE_FILTRATION);
    NODISCARD const char *getPath() const;
    void bind() const;
    void dispose() override;
};