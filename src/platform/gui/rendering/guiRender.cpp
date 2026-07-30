#include "guiRender.hpp"

#include "imgui.h"

GUIRender::GUIRender(SDL_Window& window, SDL_Renderer& renderer) : backend{window, renderer} {}

void GUIRender::newframe() {
    backend.newFrame();
    ImGui::NewFrame();
}

void GUIRender::render() {
    ImGui::Render();
    backend.render();
}