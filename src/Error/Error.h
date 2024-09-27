#pragma once

class Error {
public:
    static void fallWithMessage(const char *target, const char *description);
};