#include "guiBackend.hpp"

#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

GUIBackend::GUIBackend(SDL_Window& window, SDL_Renderer& renderer) : renderer(&renderer){
    ImGui_ImplSDL3_InitForSDLRenderer(&window, &renderer);
    ImGui_ImplSDLRenderer3_Init(&renderer);
}

GUIBackend::~GUIBackend() {
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
}

void GUIBackend::newFrame() {
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
}

void GUIBackend::render() {
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
}