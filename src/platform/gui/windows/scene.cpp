#include "scene.hpp"

#include "imgui.h"

Scene::Scene() {}

void Scene::createScene() {
    ImGui::Begin("Scene");

    ImVec2 size = ImGui::GetContentRegionAvail();

    viewport->renderResolution.height = size.y;
    viewport->renderResolution.width = size.x;

    ImGui::Image(viewport->texture, size);

    ImGui::End();
}

void Scene::setupScene(Viewport& viewport) {
    this->viewport = &viewport; 
}