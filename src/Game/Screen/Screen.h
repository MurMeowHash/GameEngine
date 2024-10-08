#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

class Screen {
private:
    static constexpr GLint UNINITIALIZED_SCREEN_SIZE{-1};
    static GLint screenWidth;
    static GLint screenHeight;
    static glm::vec4 clearColor;
public:
    static void update(GLint scrWidth, GLint scrHeight, const glm::vec3 &background);
    static void setBackgroundColor(const glm::vec3 &background);
    static void clear();
    static GLfloat getAspectRatio();
};