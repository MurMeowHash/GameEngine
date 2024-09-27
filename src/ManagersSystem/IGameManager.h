#pragma once

class IGameManager {
public:
    virtual void startUp() = 0;
    virtual ~IGameManager() = default;
};