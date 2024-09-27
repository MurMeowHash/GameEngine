#include "Debug.h"

std::ostream *Debug::debugStream;

void Debug::initialize(std::ostream *targetDebugStream) {
    debugStream = targetDebugStream;
}

void Debug::logError(const char *target, const char *description) {
    *debugStream << "ERROR::" << target << "::" << description << '\n';
}