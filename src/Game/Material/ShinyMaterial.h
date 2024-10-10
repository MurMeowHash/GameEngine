#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "BasicMaterial.h"
#include "../../Shader/ShaderType.h"

class ShinyMaterial : public BasicMaterial {
private:
    static constexpr GLfloat SHININESS_COEFFICIENT{128.0f};
    static constexpr GLfloat MIN_SHININESS{0.0f};
    static constexpr GLfloat MAX_SHININESS{1.0f};
    GLfloat shininess;
    glm::vec3 emission;
protected:
    static constexpr glm::vec3 DEFAULT_EMISSION{0.0f};
    static constexpr GLfloat DEFAULT_SHININESS{0.5f};
public:
    ShinyMaterial(ShaderType type, const char *shaderName, GLfloat shininess = DEFAULT_SHININESS,
                  const glm::vec3 &emission = DEFAULT_EMISSION);
    void setShininess(GLfloat targetShininess);
    void setEmission(const glm::vec3 &targetEmission);
    bool apply() override;
};