#include "sdlEvents.hpp"

sdlEvents::sdlEvents() {
    shouldClose = false;
}

bool sdlEvents::update() {
    inputCase();

    return shouldClose;
}


void sdlEvents::inputCase() {
    if (event.type == SDL_EVENT_QUIT) {
        shouldClose = true;
    }
}

SDL_Event* sdlEvents::getEvents() {
    return &event;
};
