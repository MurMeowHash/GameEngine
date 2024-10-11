#include "Application/Application.h"

int main() {
    Application::create(false, "Drone Game");
    Application::run();
    Application::terminate();
    return 0;
}