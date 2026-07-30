#pragma once 

#include "guiBackend.hpp"

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

class GUIRender {
public:
    GUIRender(SDL_Window& window, SDL_Renderer& renderer);
    ~GUIRender() = default;

    void newframe();
    void render();

private:
    GUIBackend backend;
};