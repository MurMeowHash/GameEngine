#pragma once

#include "Light.h"

class PointLight : public Light {
private:
    static constexpr GLfloat MIN_RADIUS{0.1f};
    static constexpr GLfloat MAX_RADIUS{100000.0f};
    static constexpr GLfloat LINEAR_MULTIPLIER{4.5f};
    static constexpr GLfloat QUADRATIC_MULTIPLIER{4.5f};
    GLfloat radius;
    GLfloat constant;
    GLfloat linear;
    GLfloat quadratic;
    static GLuint currentIndex;
protected:
    static constexpr GLfloat DEFAULT_RADIUS{10.0f};
    PointLight(std::string lightName, GLuint &index, GLfloat radius = DEFAULT_RADIUS,
               const glm::vec3 &ambient = DEFAULT_AMBIENT, const glm::vec3 &diffuse = DEFAULT_DIFFUSE,
               const glm::vec3 &specular = DEFAULT_SPECULAR, const glm::vec3 &position = DEFAULT_POS,
               const glm::vec3 &rotation = DEFAULT_ROT);
    void updateTransform() override;
public:
    explicit PointLight(GLfloat radius = DEFAULT_RADIUS, const glm::vec3 &ambient = DEFAULT_AMBIENT,
                        const glm::vec3 &diffuse = DEFAULT_DIFFUSE, const glm::vec3 &specular = DEFAULT_SPECULAR,
                        const glm::vec3 &position = DEFAULT_POS, const glm::vec3 &rotation = DEFAULT_ROT);
    void setRadius(GLfloat targetRadius);
    bool set(Shader *shader) override;
};