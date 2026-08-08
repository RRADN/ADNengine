#pragma once 

#include "imgui.h"

#include "scene.hpp"
#include "inspector.hpp"

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
    void setRect(Rect& rect);
private:
    Scene scene {};
    Inspector inspectror {};
};