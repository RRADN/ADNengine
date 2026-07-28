#pragma once

#include <SDL3/SDL.h>

class sdlContext
{
public:
    sdlContext()
    {
        #ifdef __linux__
            SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "x11");
        #endif
        
        SDL_Init(SDL_INIT_VIDEO);
    }

    ~sdlContext()
    {
        SDL_Quit();
    }
};