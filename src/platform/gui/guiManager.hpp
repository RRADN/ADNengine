#pragma once 

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

#include "windows/windowsManager.hpp"
#include "styles/guiStyle.hpp"
#include "rendering/guiRender.hpp"   

class GUI {
public:
    GUI(SDL_Window* window, SDL_Renderer* renderer, float scale);
    ~GUI() = default;

    void setupScene(Viewport& viewport);

    void update();

private:
    void newframe();
    void procesgui();
    void render();

    float  scale;

    GUIStyle guiStyle;
    GUIRender guiRender;
    GUIWindow guiWindow {};
};