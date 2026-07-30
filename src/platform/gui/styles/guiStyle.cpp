#include "guiStyle.hpp"

#include <SDL3/SDL_video.h>


GUIStyle::GUIStyle(float scale) {
    style = &ImGui::GetStyle();
    style->ScaleAllSizes(scale);
    style->FontScaleDpi = scale;
    style->FontSizeBase = 15.0f;
    ImGui::StyleColorsDark();
}