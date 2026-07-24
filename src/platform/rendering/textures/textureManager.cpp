#include "textureManager.hpp"

TextureManager::TextureManager(SDL_Renderer& renderer) :
    textures(renderer, getTexturesPath()),
    screens(renderer, getScreensPath())
{}