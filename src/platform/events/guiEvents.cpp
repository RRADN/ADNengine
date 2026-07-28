#include "guiEvents.hpp"

#include "imgui_impl_sdl3.h"


guiEvents::guiEvents() {};

void guiEvents::update(SDL_Event* event) {
    ImGui_ImplSDL3_ProcessEvent(event);
}