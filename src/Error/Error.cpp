#include "Error.h"
#include "../Debug/Debug.h"
#include "../Application/Application.h"

void Error::fallWithMessage(const char *target, const char *description) {
    Debug::logError(target, description);
    Application::shut();
}