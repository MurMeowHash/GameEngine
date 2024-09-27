#include "Game.h"
#include "../Error/Error.h"
#include "../utils/utils.h"
#include "Time.h"

Game::Game(bool fullscreen, const char *title, const glm::vec3 &background)
: fullscreen(fullscreen), title{title} {
    setBackgroundColor(background);
}

void Game::createWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    auto currentMonitor = glfwGetPrimaryMonitor();
    auto screen = glfwGetVideoMode(currentMonitor);
    screenWidth = screen->width;
    screenHeight = screen->height;
    auto targetMonitor = fullscreen ? currentMonitor : nullptr;
    mainWindow = glfwCreateWindow(screenWidth, screenHeight, title, targetMonitor, nullptr);
    if(!mainWindow) {
        Error::fallWithMessage("WINDOW", "FAILED_TO_CREATE");
    }
    glfwMakeContextCurrent(mainWindow);
}

void Game::clearScreen() const {
    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Game::loadGLFunctions() {
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        Error::fallWithMessage("OPENGL_FUNCTIONS", "FAILED_TO_LOAD");
    }
}

void Game::setBackgroundColor(const glm::vec3 &background) {
    clearColor = glm::vec4(rgb_to_normalized(background), 1.0f);
}

void Game::create() {
    createWindow();
    loadGLFunctions();
}

void Game::update() {
    while(!glfwWindowShouldClose(mainWindow)) {
        clearScreen();
        Time::calculateDeltaTime();
        //main loop
        glfwSwapBuffers(mainWindow);
        glfwPollEvents();
    }
}

void Game::terminate() {

}
