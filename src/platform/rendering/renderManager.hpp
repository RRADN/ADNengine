#pragma once

#include <SDL3/SDL.h>

#include "textures/textureManager.hpp"

#include "../../core/dataTipes/inputs.hpp"

#include "../../core/dataTipes/resolution.hpp"

#include "../../core/dataTipes/rect.hpp"

class Render{
public:
    Render(SDL_Renderer& renderer, SystemInputs& inputs);
    ~Render() = default;

    void draw(TexturesID id, const Rect& rect);
    void draw(ScreensID id);

    
private:

    SystemInputs* inputs;

    SDL_Renderer* renderer;

    TextureManager textures;
};