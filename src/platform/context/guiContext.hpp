#pragma once

#include "imgui.h"
#include "imgui_impl_sdl3.h"


class guiContext {
public:
    guiContext() {
        IMGUI_CHECKVERSION();
        context = ImGui::CreateContext();
        io = &ImGui::GetIO(); (void)io;
        io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  
        io->Fonts->AddFontFromFileTTF("assets/fonts/Orbitron.ttf");

        
        
    }

    ~guiContext() { 
        ImGui::DestroyContext(context);
        io = nullptr;
    }

private:
    ImGuiContext * context;
    ImGuiIO* io;
};