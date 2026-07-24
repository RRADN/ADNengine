#pragma once

#include <string>
#include <unordered_map>

#include "../ids/fontsID.hpp"

inline std::unordered_map<FontsID, std::string> getFontsPath() {
   return {
    {FontsID::Geistpixel, "assets/fonts/GeistPixel.ttf"},
    {FontsID::Orbitron, "assets/fonts/Orbitron.ttf"}
   };
}