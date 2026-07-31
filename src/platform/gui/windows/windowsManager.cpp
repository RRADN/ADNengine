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
    ImGui::Begin("Scene");

    ImVec2 size = ImGui::GetContentRegionAvail();

    ImGui::InvisibleButton("SceneViewport", size);

    // Después aquí dibujarás la textura del renderer:
    // ImGui::Image(texture, size);

    ImGui::End();
}

void GUIWindow::createInspector() {
    ImGui::Begin("Inspector");

    ImGui::Text("Selected Entity");

    static char name[64] = "Player";

    ImGui::InputText("Name", name, sizeof(name));

    static float position[2]{0.0f,0.0f};

    ImGui::DragFloat2("Position", position);

    static float rotation = 0.0f;

    ImGui::DragFloat("Rotation",&rotation);

    static float scale[2]{1.0f,1.0f};

    ImGui::DragFloat2("Scale", scale);

    ImGui::End();
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