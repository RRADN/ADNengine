#include "eventsManager.hpp"

Events::Events() {};

bool Events::update() {
    while (SDL_PollEvent(sdl.getEvents())) {

        gui.update(sdl.getEvents());

        return sdl.update();
    }
    return false;
}