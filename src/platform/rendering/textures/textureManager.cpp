#include "textureManager.hpp"

TextureManager::TextureManager(SDL_Renderer* renderer) :
    textures(*renderer, getTexturesPath()),
    screens(*renderer, getScreensPath()) {
    
    viewportTexture = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    1920, 1080);

}

TextureManager::~TextureManager() {
    SDL_DestroyTexture(viewportTexture);
}



