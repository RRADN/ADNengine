#pragma once

#include <SDL3/SDL_events.h>

class guiEvents {
public:
    guiEvents();
    ~guiEvents() = default;

    void update(SDL_Event* event);

};