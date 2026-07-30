#pragma once 

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

class GUIBackend {
public:
    GUIBackend(SDL_Window& window, SDL_Renderer& renderer);
    ~GUIBackend();

    void newFrame();
    void render();

private: 
    SDL_Renderer* renderer;
};