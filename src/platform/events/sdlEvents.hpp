#pragma once 

#include <SDL3/SDL_events.h>

class sdlEvents {
public:
    sdlEvents();
    ~sdlEvents() = default;

    SDL_Event* getEvents();

    bool update();

private:
    bool shouldClose;

    SDL_Event event {};

    void inputCase();
};