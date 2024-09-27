#include "Shader.h"
#include "../Error/Error.h"
#include "../Debug/Debug.h"
#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char *vertexPath, const char *fragmentPath) {
    std::string vertexCode = loadCode(vertexPath);
    std::string fragmentCode = loadCode(fragmentPath);
    const char *vertexShaderCode = vertexCode.c_str();
    const char *fragmentShaderCode = fragmentCode.c_str();
    GLuint vertexShader = compileShader(vertexShaderCode, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragmentShaderCode, GL_FRAGMENT_SHADER);
    createProgram(vertexShader, fragmentShader);
}

std::string Shader::loadCode(const char *path) {
    std::ifstream codeStream{path};
    if(!codeStream) {
        Error::fallWithMessage("SHADER", "FAILED_TO_LOAD_CODE");
    }
    std::stringstream ss;
    ss << codeStream.rdbuf();
    return ss.str();
}

GLuint Shader::compileShader(const char *code, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &code, nullptr);
    glCompileShader(shader);
    GLint compiled;
    char infoLog[BUFSIZ];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if(!compiled) {
        glGetShaderInfoLog(shader, BUFSIZ, nullptr, infoLog);
        Error::fallWithMessage("SHADER", infoLog);
    }
    return shader;
}

void Shader::createProgram(GLuint vertexShader, GLuint fragmentShader) {
    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);
    GLint linked;
    char infoLog[BUFSIZ];
    glGetProgramiv(id, GL_LINK_STATUS, &linked);
    if(!linked) {
        glGetProgramInfoLog(id, BUFSIZ, nullptr, infoLog);
        Error::fallWithMessage("SHADER_PROGRAM", infoLog);
    }
}

void Shader::use() const {
    glUseProgram(id);
}

void Shader::setUniform(const char *name, const std::function<void(GLint)> &uniformFunc) const {
    GLint location = glGetUniformLocation(id, name);
    if(location == INVALID_LOCATION) {
        std::string description = "INVALID_UNIFORM_NAME::" + std::string(name);
        Debug::logError("SHADER", description.c_str());
    } else {
        uniformFunc(location);
    }
}

void Shader::setFloat(const char *name, GLfloat value) const {
    setUniform(name, [value](GLint location){
        glUniform1f(location, value);
    });
}

void Shader::setInt(const char *name, GLint value) const {
    setUniform(name, [value](GLint location){
        glUniform1i(location, value);
    });
}

void Shader::setMat3(const char *name, const glm::mat3 &value) const {
    setUniform(name, [&value](GLint location){
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
    });
}

void Shader::setMat4(const char *name, const glm::mat4 &value) const {
    setUniform(name, [&value](GLint location){
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    });
}

void Shader::setVec3(const char *name, const glm::vec3 &value) const {
    setUniform(name, [&value](GLint location){
        glUniform3fv(location, 1, glm::value_ptr(value));
    });
}
