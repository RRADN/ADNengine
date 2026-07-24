#include "renderManager.hpp"

Render::Render(SDL_Renderer& renderer, SystemInputs& inputs, Resolution resolution) : textures{renderer} {
    this->renderer = &renderer;
    this->inputs = &inputs;
    this->resolution = resolution;
}

void Render::draw(TexturesID id, const SDL_FRect& destRect) {
    SDL_RenderTexture(renderer, textures.textures.getTexure(id), nullptr, &destRect);
    if (inputs->debuging) {
        SDL_RenderTexture(renderer, textures.textures.getTexure(id), nullptr, &destRect);
    }
}

void Render::draw(ScreensID id) {
    SDL_FRect destRect {0.0f, 0.0f, resolution.width, resolution.height};
    SDL_RenderTexture(renderer, textures.screens.getTexure(id), nullptr, &destRect);
    if (inputs->debuging) {
       SDL_RenderTexture(renderer, textures.screens.getTexure(id), nullptr, &destRect);
    }
}

/*
void Render::drawMap(std::vector<std::vector<Tile<TileID>>> tileMap) {
    int i = 0;
    for (auto& row : tileMap) {
        for (int j = 0; j < 10; j++){
            if (tileMap[i][j].isVisible()){
                const SDL_FRect destRect = {tileMap[i][j].getX(),tileMap[i][j].getY(),
                                        textures.tiles.getWidth(tileMap[i][j].getID()),
                                        textures.tiles.getHeight(tileMap[i][j].getID())}; 
                SDL_RenderTexture(renderer, textures.tiles.getTexure(tileMap[i][j].getID()), nullptr, &destRect);
                if (inputs->debuging) {

                }
            }
            
        }
        i++;
    }
}
    */