#include <iostream>
#include "Debug/Debug.h"
#include "Game/Game.h"
#include "ManagersSystem/Managers.h"

void initialize();
void terminate();

int main() {
    initialize();

    auto currentGame = new Game{true, "Drone Simulator"};
    Managers::getGameManager()->setCurrentGame(currentGame);
    currentGame->create();
    currentGame->update();

    delete currentGame;
    terminate();
    return 0;
}

void initialize() {
    Debug::initialize(&std::cout);
    Managers::startManagers();
}

void terminate() {
    Managers::terminate();
}