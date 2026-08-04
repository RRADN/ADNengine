#include "scene.hpp"

#include "imgui.h"

Scene::Scene() {}

void Scene::createScene() {
    ImGui::Begin("Scene");

    ImVec2 size = ImGui::GetContentRegionAvail();

    ImGui::InvisibleButton("SceneViewport", size);

    ImGui::Image(viewport->texture, {viewport->windowResolution.width, viewport->windowResolution.height});

    ImGui::End();
}

void Scene::setupScene(Viewport& viewport) {

}