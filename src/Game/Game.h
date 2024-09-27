#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "IUpdatable.h"

class Game : public IUpdatable {
private:
    static constexpr const char *DEFAULT_TITLE{"OpenGL Application"};
    static constexpr glm::vec3 DEFAULT_CLEAR_COLOR{124.0f, 194.0f, 255.0f};
    GLFWwindow *mainWindow;
    bool fullscreen;
    const char *title;
    glm::vec4 clearColor;
    int screenWidth;
    int screenHeight;
    void createWindow();
    void clearScreen() const;
    static void loadGLFunctions();
public:
    explicit Game(bool fullscreen = false, const char *title = DEFAULT_TITLE, const glm::vec3 &background = DEFAULT_CLEAR_COLOR);
    void setBackgroundColor(const glm::vec3 &background);
    void create();
    void terminate();
    void update() override;
};