#pragma once 

#include "imgui.h"

class GUIWindow {
public:
    GUIWindow() {};
    ~GUIWindow() = default;

    void createDockspace(){
        ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());
    }

    
};