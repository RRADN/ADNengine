#include "textureManager.hpp"

TextureManager::TextureManager(SDL_Renderer& renderer) :
    textures(renderer, getTexturesPath()),
    screens(renderer, getScreensPath()) {
    
    viewport->texture = SDL_CreateTexture(
    &renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    1280,
    720 );

}