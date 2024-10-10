#include "Application/Application.h"

int main() {
    Application::create(true, "Drone Game");
    Application::run();
    Application::terminate();
    return 0;
}