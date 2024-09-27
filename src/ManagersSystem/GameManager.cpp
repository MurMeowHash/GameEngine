#include "GameManager.h"
#include "../Debug/Debug.h"

void GameManager::startUp() {
    Debug::log("Game manager is starting...");
    currentGame = nullptr;
}

void GameManager::setCurrentGame(Game *targetGame) {
    currentGame = targetGame;
}

Game *GameManager::getCurrentGame() const {
    return currentGame;
}