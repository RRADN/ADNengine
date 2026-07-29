#pragma once

#include "sdlContext.hpp"
#include "guiContext.hpp"

class Context {
public:
    Context();
    ~Context() = default;

private:
    sdlContext window;
    guiContext gui;
};