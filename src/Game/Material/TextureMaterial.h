#pragma once

#include "ShinyMaterial.h"
#include "../Texture/Texture2D.h"

class TextureMaterial : public ShinyMaterial {
private:
    Texture2D *diffuse;
    Texture2D *specular;
    static void setMap(Texture2D *src, Texture2D *&dest);
public:
    explicit TextureMaterial(Texture2D *diffuse = nullptr, Texture2D *specular = nullptr,
                             GLfloat shininess = DEFAULT_SHININESS, const glm::vec3 &emission = DEFAULT_EMISSION);
    void setDiffuse(Texture2D *diffuseMap);
    void setSpecular(Texture2D *specularMap);
    bool apply() override;
};