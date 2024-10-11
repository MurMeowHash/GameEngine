#pragma once

#include "Light.h"

class DirectionalLight : public Light {
private:
    glm::vec3 rayDirection;
    static GLuint currentIndex;
protected:
    void updateTransform() override;
public:
    explicit DirectionalLight(const glm::vec3 &ambient = DEFAULT_AMBIENT, const glm::vec3 &diffuse = DEFAULT_DIFFUSE,
                              const glm::vec3 &specular = DEFAULT_SPECULAR, const glm::vec3 &position = DEFAULT_POS,
                              const glm::vec3 &rotation = DEFAULT_ROT);
    bool set(Shader *shader) override;
};