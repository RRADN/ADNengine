#include "inspector.hpp"

#include "imgui.h"

Inspector::Inspector() {}

void Inspector::createInspector() {
    if (rect != nullptr) {
        ImGui::Begin("Inspector");

        ImGui::Text("Selected Entity");

        static char name[64] = "Player";

        ImGui::InputText("Name", name, sizeof(name));

        ImGui::DragFloat("Position X", &rect->x);

        ImGui::DragFloat("Position Y", &rect->y);

        ImGui::DragFloat("Scale x", &rect->width, 0.01f, -100.0f, 100.0f);

        ImGui::DragFloat("Scale Y", &rect->height, 0.01f, -100.0f, 100.0f);    

        ImGui::End();
    }
}

void Inspector::setRect(Rect& rect) {
    this->rect = &rect;
}