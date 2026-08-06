#include "scene.hpp"

#include "imgui.h"

Scene::Scene() {}

void Scene::createScene() {
    ImGui::Begin("Scene", nullptr,
    ImGuiWindowFlags_NoScrollbar |
    ImGuiWindowFlags_NoScrollWithMouse);

    ImVec2 size = ImGui::GetContentRegionAvail();

    viewport->renderResolution.height = size.y;
    viewport->renderResolution.width = size.x;

    verifySize();

    ImVec2 cursor = ImGui::GetCursorPos();

    cursor.x += (size.x - viewport->renderResolution.width) * 0.5f;
    cursor.y += (size.y - viewport->renderResolution.height) * 0.5f;

    ImGui::SetCursorPos(cursor);

    ImGui::Image(viewport->texture, {viewport->renderResolution.width, viewport->renderResolution.height});

    ImGui::End();
}

void Scene::verifySize() {
    if(viewport->renderResolution.width / viewport->renderResolution.height == viewport->proportion) {
        return;
    } else if (viewport->renderResolution.width / viewport->renderResolution.height > viewport->proportion) {
        viewport->renderResolution.width = viewport->renderResolution.height * viewport->proportion;
    } else {
        viewport->renderResolution.height = viewport->renderResolution.width / viewport->proportion;
    }
}

void Scene::setupScene(Viewport& viewport) {
    this->viewport = &viewport; 
}