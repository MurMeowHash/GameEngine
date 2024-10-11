#pragma once

#include "BasicMaterial.h"

class LightMaterial : public BasicMaterial {
private:
    glm::vec3 color;
public:
    explicit LightMaterial(const glm::vec3 &color);
    void setColor(const glm::vec3 &targetColor);
    bool apply() override;
};