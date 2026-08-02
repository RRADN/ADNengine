#include "guiManager.hpp"

GUI::GUI(SDL_Window* window, SDL_Renderer* renderer, float scale) : 
            scale(scale),
            guiRender(*window, *renderer),
            guiStyle(scale)  {}

void GUI::setupScene(Viewport& viewport) {
    guiWindow.setupScene(viewport);
}

void GUI::update() {
    newframe();
    procesgui();
    render();
}

void GUI::newframe() {
    guiRender.newframe();
}

void GUI::procesgui() {
    guiWindow.createDockspace();
    guiWindow.createToolbar();
    guiWindow.createHierarchy();
    guiWindow.createScene();
    guiWindow.createInspector();
    guiWindow.createConsole();
}

void GUI::render() {
    guiRender.render();
}