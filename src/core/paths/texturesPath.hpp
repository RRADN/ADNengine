#pragma once

#include <string>
#include <unordered_map>

#include "../ids/texturesID.hpp"

inline std::unordered_map<TexturesID, std::string> getTexturesPath() {
   return {
    {TexturesID::No_texture, "assets/textures/no_texture.png"}
   };
}