#pragma once

#include "ManagerState.h"
#include "../utils/utils.h"

class AbstractManager {
protected:
    ManagerState state;
    static void logManagerLoading(const char *managerName);
public:
    explicit AbstractManager();
    NODISCARD ManagerState getState() const;
    virtual void startUp() = 0;
    virtual ~AbstractManager() = default;
};