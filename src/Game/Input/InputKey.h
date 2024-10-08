#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

static constexpr GLuint KEY_COUNT{349};

enum class InputKey {
    KeyEsc = GLFW_KEY_ESCAPE,
    KeyW = GLFW_KEY_W,
    KeyS = GLFW_KEY_S,
    KeyA = GLFW_KEY_A,
    KeyD = GLFW_KEY_D,
    KeyUndefined = GLFW_KEY_UNKNOWN
};