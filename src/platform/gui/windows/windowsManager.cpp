#include "windowsManager.hpp"

GUIWindow::GUIWindow() {}

void GUIWindow::createDockspace() {
    ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());
}

void GUIWindow::createToolbar() {
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            ImGui::MenuItem("New Scene");
            ImGui::MenuItem("Open");
            ImGui::MenuItem("Save");
            ImGui::Separator();
            ImGui::MenuItem("Exit");
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit"))
        {
            ImGui::MenuItem("Undo");
            ImGui::MenuItem("Redo");
            ImGui::EndMenu();
        }

        ImGui::Separator();

        if (ImGui::Button("▶ Play")) {}
        ImGui::SameLine();
        if (ImGui::Button("⏸ Pause")) {}
        ImGui::SameLine();
        if (ImGui::Button("■ Stop")) {}

        ImGui::EndMainMenuBar();
    }

}

void GUIWindow::createHierarchy() {
    ImGui::Begin("Hierarchy");

    if (ImGui::TreeNode("Scene"))
    {
        ImGui::Selectable("Camera");
        ImGui::Selectable("Player");
        ImGui::Selectable("Enemy");
        ImGui::Selectable("Light");

        ImGui::TreePop();
    }

    ImGui::End();
}

void GUIWindow::createScene() {
    scene.createScene();
}

void GUIWindow::createInspector() {
    inspectror.createInspector();
}

void GUIWindow::createConsole() {
    ImGui::Begin("Console");

    ImGui::TextColored(ImVec4(0,1,0,1), "[INFO] Engine started.");
    ImGui::TextColored(ImVec4(1,1,0,1), "[WARN] Missing texture.");
    ImGui::TextColored(ImVec4(1,0,0,1), "[ERROR] Failed to load asset.");

    if (ImGui::Button("Clear"))
    {
        // console.clear();
    }

    ImGui::End();
}

void GUIWindow::setupScene(Viewport& viewport) {
    scene.setupScene(viewport);
}

void GUIWindow::setRect(Rect& rect) {
    inspectror.setRect(rect);
}
