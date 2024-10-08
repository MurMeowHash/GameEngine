#pragma once

#include <ostream>
#include <glad/glad.h>

class Debug {
private:
    static std::ostream *debugStream;
    static void logErrorRaw(const char *target, const char *description);
public:
    static void initialize(std::ostream *targetDebugStream);

    template<typename T>
    static void log(T value) {
        *debugStream << value << '\n';
    }
    static void logError(const char *target, const char *description);
    static void logError(const char *target, const char *description, const char *object);
};