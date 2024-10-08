#include "Game.h"
#include "../Error/Error.h"
#include "Time.h"
#include "Input/Input.h"
#include "Screen/Screen.h"
#include "../Debug/Debug.h"

Game::Game(bool fullscreen, const char *title)
: fullscreen(fullscreen), title{title} {

}

void Game::createWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    auto currentMonitor = glfwGetPrimaryMonitor();
    auto screen = glfwGetVideoMode(currentMonitor);
    int screenWidth = screen->width;
    int screenHeight = screen->height;
    auto targetMonitor = fullscreen ? currentMonitor : nullptr;
    window = glfwCreateWindow(screenWidth, screenHeight, title, targetMonitor, nullptr);
    if(!window) {
        Error::fallWithMessage("WINDOW", "FAILED_TO_CREATE");
    }
    glfwMakeContextCurrent(window);
    Screen::update(screenWidth, screenHeight, DEFAULT_BACKGROUND);
}

void Game::setCallbacks() {
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

}

void Game::loadGLFunctions() {
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        Error::fallWithMessage("OPENGL_FUNCTIONS", "FAILED_TO_LOAD");
    }
}

void Game::create() {
    createWindow();
    loadGLFunctions();
    setCallbacks();
    Input::initialize();
}

void Game::terminate() {

}

GLFWwindow *Game::getWindow() const {
    return window;
}

void Game::update() {
    while(!glfwWindowShouldClose(window)) {
        Screen::clear();
        Time::calculateDeltaTime();
        processSystemInput();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Game::framebuffer_size_callback(UNUSED GLFWwindow *targetWindow, int width, int height) {
    glViewport(0, 0, width, height);
}

void Game::processSystemInput() {
    if(Input::getKeyDown(InputKey::KeyEsc)) {
        glfwSetWindowShouldClose(window, true);
    }
}