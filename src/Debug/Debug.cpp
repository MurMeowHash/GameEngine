#include "Debug.h"

std::ostream *Debug::debugStream;

void Debug::initialize(std::ostream *targetDebugStream) {
    debugStream = targetDebugStream;
}

void Debug::logErrorRaw(const char *target, const char *description) {
    *debugStream << "ERROR::" << target << "::" << description;
}

void Debug::logError(const char *target, const char *description) {
    logErrorRaw(target, description);
    *debugStream << '\n';
}

void Debug::logError(const char *target, const char *description, const char *object) {
    logErrorRaw(target, description);
    *debugStream << "::" << object << '\n';
}