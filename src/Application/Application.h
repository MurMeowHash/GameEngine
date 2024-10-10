#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Game/Game.h"

class Application {
private:
    static Game *currentGame;
    static void initGLFW();
public:
    static void create(bool fullscreen, const char *title);
    static void run();
    static void terminate();
    static void shut();
};