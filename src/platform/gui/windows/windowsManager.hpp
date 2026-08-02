#pragma once 

#include "imgui.h"

#include "scene.hpp"

class GUIWindow {
public:
    GUIWindow();
    ~GUIWindow() = default;

    void createDockspace();
    void createToolbar();
    void createHierarchy();
    void createScene();
    void createInspector();
    void createConsole();

    void setupScene(Viewport& viewport);

private:
    Scene scene {};
};