#pragma once

class IUpdatable {
public:
    virtual void update() = 0;
    virtual ~IUpdatable() = default;
};