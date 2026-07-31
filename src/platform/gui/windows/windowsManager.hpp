#pragma once 

#include "imgui.h"

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
};