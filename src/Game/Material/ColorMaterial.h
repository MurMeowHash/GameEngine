#pragma once

#include "ShinyMaterial.h"

class ColorMaterial : public ShinyMaterial {
private:
    static constexpr glm::vec3 DEFAULT_DIFFUSE{159.0f};
    static constexpr glm::vec3 DEFAULT_SPECULAR{183.0f};
    glm::vec3 diffuse;
    glm::vec3 specular;
public:
    explicit ColorMaterial(const glm::vec3 &diffuse = DEFAULT_DIFFUSE, const glm::vec3 &specular = DEFAULT_SPECULAR,
                           GLfloat shininess = DEFAULT_SHININESS, const glm::vec3 &emission = DEFAULT_EMISSION);
    void setDiffuse(const glm::vec3 &diffuseColor);
    void setSpecular(const glm::vec3 &specularColor);
    bool apply() override;
};