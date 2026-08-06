#pragma once

#include <SDL3/SDL_render.h>

#include "resolution.hpp"

struct Viewport {
    SDL_Texture* texture;

    Resolution windowResolution;
    Resolution renderResolution;

    float proportion;
};