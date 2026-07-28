#pragma once

#include "sdlEvents.hpp"
#include "guiEvents.hpp"

class Events {
public:
    Events();
    ~Events() = default;

    bool update();

private:
    sdlEvents sdl;
    guiEvents gui;
};