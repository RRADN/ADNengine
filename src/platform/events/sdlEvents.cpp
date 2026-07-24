#include "sdlEvents.hpp"

#include <iostream>
#include <SDL3/SDL_events.h>

Events::Events() {
    shouldClose = false;
}

bool Events::update() {
    inputCase();
    
    return !shouldClose;
}


void Events::inputCase() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            shouldClose = true;
        }
    }  
}
