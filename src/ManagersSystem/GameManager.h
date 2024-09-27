#pragma once

#include "IGameManager.h"
#include "../Game/Game.h"
#include "../utils/utils.h"

class GameManager : public IGameManager {
private:
    Game *currentGame;
public:
    void startUp() override;
    void setCurrentGame(Game *targetGame);
    NODISCARD Game *getCurrentGame() const;
};