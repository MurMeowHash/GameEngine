#pragma once

class IDisposable {
public:
    virtual void dispose() = 0;
    virtual ~IDisposable() = default;
};