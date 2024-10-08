#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "IUpdatable.h"
#include "../utils/utils.h"

class Game : public IUpdatable {
private:
    static constexpr const char *DEFAULT_TITLE{"OpenGL Application"};
    static constexpr glm::vec3 DEFAULT_BACKGROUND{124.0f, 194.0f, 255.0f};
    GLFWwindow *window;
    bool fullscreen;
    const char *title;
    void createWindow();
    void setCallbacks();
    void processSystemInput();
    static void loadGLFunctions();
public:
    explicit Game(bool fullscreen = false, const char *title = DEFAULT_TITLE);
    void create();
    void terminate();
    NODISCARD GLFWwindow *getWindow() const;
    void update() override;
    static void framebuffer_size_callback(UNUSED GLFWwindow *targetWindow, int width, int height);
};