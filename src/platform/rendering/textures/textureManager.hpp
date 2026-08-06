#pragma once

#include "textureMap.hpp"

//IDs
#include "../../../core/ids/texturesID.hpp"
#include "../../../core/ids/screensID.hpp"

//Paths
#include "../../../core/paths/texturesPath.hpp"
#include "../../../core/paths/screensPath.hpp"

#include "../../../core/dataTipes/viewPort.hpp"

class TextureManager {
public:
    TextureManager(SDL_Renderer* renderer);
    ~TextureManager();

    SDL_Texture* viewportTexture;
    
    TextureMap<TexturesID> textures;
    TextureMap<ScreensID> screens; 
};