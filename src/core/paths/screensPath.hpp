#pragma once

#include <string>
#include <unordered_map>

#include "../ids/screensID.hpp"

inline std::unordered_map<ScreensID, std::string> getScreensPath() {
   return {
    {ScreensID::Adn_black, "assets/screens/adn_black.png"},
    {ScreensID::Adn_white, "assets/screens/adn_white.png"}
   };
}