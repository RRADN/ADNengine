#pragma once

#include <SDL3/SDL.h>

#include "textures/textureManager.hpp"

#include "../../logic/input/inputs.hpp"

#include "../../core/config/resolution.hpp"

//std
#include <stdexcept>
#include <vector>

class Render{
public:
    Render(SDL_Renderer& renderer, SystemInputs& inputs, Resolution resolution);
    ~Render() = default;

    void draw(TexturesID id, const SDL_FRect& destRect);
    void draw(ScreensID id);
    //void drawMap(std::vector<std::vector<Tile<TileID>>> tileMap);

private:
    Resolution resolution;

    SystemInputs* inputs;

    SDL_Renderer* renderer;

    TextureManager textures;
};