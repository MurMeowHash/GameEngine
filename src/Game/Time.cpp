#include "Time.h"
#include <GLFW/glfw3.h>

GLfloat Time::lastTime{0};
GLfloat Time::deltaTime;

void Time::calculateDeltaTime() {
    auto currentTime = static_cast<GLfloat>(glfwGetTime());
    deltaTime = currentTime - lastTime;
    lastTime = deltaTime;
}

GLfloat Time::getDeltaTime() {
    return deltaTime;
}
