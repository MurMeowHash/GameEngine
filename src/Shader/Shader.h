#pragma once

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <functional>
#include "../utils/utils.h"
#include "../Dispose/IDisposable.h"

class Shader : public IDisposable {
private:
    static constexpr GLint INVALID_LOCATION{-1};
    GLuint id;
    static std::string loadCode(const char *path);
    static GLuint compileShader(const char *code, GLenum shaderType);
    void createProgram(GLuint vertexShader, GLuint fragmentShader);
    void setUniform(const char *name, const std::function<void(GLint)> &uniformFunc) const;
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    void use() const;
    void setFloat(const char *name, GLfloat value) const;
    void setInt(const char *name, GLint value) const;
    void setMat3(const char *name, const glm::mat3 &value) const;
    void setMat4(const char *name, const glm::mat4 &value) const;
    void setVec3(const char *name, const glm::vec3 &value) const;
    void dispose() override;
};