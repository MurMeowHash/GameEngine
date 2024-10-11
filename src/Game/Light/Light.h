#pragma once

#include "../GameObject.h"
#include <glm/glm.hpp>
#include "../../Shader/Shader.h"

class Light : public GameObject {
private:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
protected:
    static constexpr glm::vec3 DEFAULT_AMBIENT{30.0f};
    static constexpr glm::vec3 DEFAULT_DIFFUSE{120.0f};
    static constexpr glm::vec3 DEFAULT_SPECULAR{150.0f};
    std::string lightName;
public:
    Light(std::string lightName, GLuint &currentIndex, const glm::vec3 &ambient = DEFAULT_AMBIENT,
          const glm::vec3 &diffuse = DEFAULT_DIFFUSE, const glm::vec3 &specular = DEFAULT_SPECULAR,
          const glm::vec3 &position = DEFAULT_POS, const glm::vec3 &rotation = DEFAULT_ROT);
    void setAmbient(const glm::vec3 &ambientLight);
    void setDiffuse(const glm::vec3 &diffuseLight);
    void setSpecular(const glm::vec3 &specularLight);
    void init(std::string &&name, GLuint &currentIndex);
    virtual bool set(Shader *shader) = 0;
};