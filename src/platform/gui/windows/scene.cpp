#include "scene.hpp"

#include "imgui.h"

Scene::Scene() {}

void Scene::createScene() {
    ImGui::Begin("Scene");

    ImVec2 size = ImGui::GetContentRegionAvail();

    ImGui::InvisibleButton("SceneViewport", size);

    // Después aquí dibujarás la textura del renderer:
    // ImGui::Image(texture, size);

    ImGui::End();
}

void Scene::setupScene(Viewport& viewport) {

}