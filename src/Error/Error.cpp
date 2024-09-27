#include "Error.h"
#include "../Debug/Debug.h"
#include "../ManagersSystem/Managers.h"

void Error::fallWithMessage(const char *target, const char *description) {
    Debug::logError(target, description);
    Managers::getGameManager()->getCurrentGame()->terminate();
}