#include "Application.h"
#include "../Debug/Debug.h"
#include "../ManagersSystem/Managers.h"
#include <iostream>

Game *Application::currentGame{nullptr};

void Application::create(bool fullscreen, const char *title) {
    Debug::initialize(&std::cout);
    initGLFW();
    currentGame = Game::getInstance(fullscreen, title);
    currentGame->create();
    Managers::startManagers();
}

void Application::initGLFW() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Application::run() {
    currentGame->update();
}

void Application::shut() {
    terminate();
    exit(0);
}

void Application::terminate() {
    Managers::shut();
    currentGame->dispose();
    Game::deleteInstance();
    glfwTerminate();
}