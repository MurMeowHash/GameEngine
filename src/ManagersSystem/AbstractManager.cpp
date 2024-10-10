#include "AbstractManager.h"
#include "../Debug/Debug.h"

AbstractManager::AbstractManager() : state{ManagerState::Shutdown} {

}

ManagerState AbstractManager::getState() const {
    return state;
}

void AbstractManager::logManagerLoading(const char *managerName) {
    Debug::log(std::string(managerName) + " manager is starting...");
}