#pragma once

#include "imgui.h"

class GUIStyle {
public:
    GUIStyle(float);
    ~GUIStyle() = default;
private:
    ImGuiStyle* style;
};