#include "guiManager.hpp"



GUI::GUI(SDL_Window* window, SDL_Renderer* renderer, float scale) : scale(scale),
            window(window),
            renderer(renderer), 
            guiRender(*window, *renderer),
            guiStyle(scale)  {}

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
}

void GUI::render() {
    guiRender.render();
}