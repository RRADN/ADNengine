#include "renderManager.hpp"

Render::Render(SDL_Renderer& renderer, SystemInputs& inputs) : textures{renderer} {
    this->renderer = &renderer;
    this->inputs = &inputs;

    SDL_SetRenderTarget(&renderer, textures.viewport->texture);
}

void Render::draw(TexturesID id, const Rect& rect) {
    SDL_FRect destRect = {rect.x, rect.y, rect.width, rect.height};
    SDL_RenderTexture(renderer, textures.textures.getTexure(id), nullptr, &destRect);
    if (inputs->debuging) {
        SDL_RenderTexture(renderer, textures.textures.getTexure(id), nullptr, &destRect);
    }
}

void Render::draw(ScreensID id) {
    SDL_FRect destRect {0.0f, 0.0f, 1920, 1080};
    SDL_RenderTexture(renderer, textures.screens.getTexure(id), nullptr, &destRect);
    if (inputs->debuging) {
       SDL_RenderTexture(renderer, textures.screens.getTexure(id), nullptr, &destRect);
    }
}
