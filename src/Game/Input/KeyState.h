#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum class KeyState {
    Press = GLFW_PRESS,
    Release = GLFW_RELEASE,
    Hold = GLFW_REPEAT,
    Unknown
};