#include "ShaderHash.h"
#include "Shader.h"

size_t ShaderHash::operator()(const Shader &shader) const {
    return std::hash<GLuint>()(shader.id);
}