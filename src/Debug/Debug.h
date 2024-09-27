#pragma once

#include <ostream>
#include <glad/glad.h>

class Debug {
private:
    static std::ostream *debugStream;
public:
    static void initialize(std::ostream *targetDebugStream);

    template<typename T>
    static void log(T value) {
        *debugStream << value << '\n';
    }
    static void logError(const char *target, const char *description);
};