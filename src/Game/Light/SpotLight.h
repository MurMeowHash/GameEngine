#pragma once

#include "PointLight.h"

class SpotLight : public PointLight {
private:
    static constexpr GLfloat DEFAULT_INNER_CUT_OFF{10.0f};
    static constexpr GLfloat DEFAULT_OUTER_CUT_OFF{15.0f};
    static constexpr GLfloat MIN_CUT_OFF{0.0f};
    static constexpr GLfloat MAX_CUT_OFF{180.0f};
    GLfloat innerCutOff;
    GLfloat outerCutOff;
    static GLuint currentIndex;
public:
    explicit SpotLight(GLfloat innerCutOff = DEFAULT_INNER_CUT_OFF, GLfloat outerCutOff = DEFAULT_OUTER_CUT_OFF,
              GLfloat radius = DEFAULT_RADIUS, const glm::vec3 &ambient = DEFAULT_AMBIENT,
              const glm::vec3 &diffuse = DEFAULT_DIFFUSE, const glm::vec3 &specular = DEFAULT_SPECULAR,
              const glm::vec3 &position = DEFAULT_POS, const glm::vec3 &rotation = DEFAULT_ROT);
    void setInnerCutOff(GLfloat cutOff);
    void setOuterCutOff(GLfloat cutOff);
    bool set(Shader *shader) override;
};