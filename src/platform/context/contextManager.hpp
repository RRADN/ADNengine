#pragma once

#include "sdlContext.hpp"

class Context {
public:
    Context();
    ~Context() = default;

private:
    sdlContext window {};

};