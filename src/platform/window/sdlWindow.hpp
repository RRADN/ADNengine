#pragma once

#include <SDL3/SDL.h>
#include <string>

#include "../../core/dataTipes/resolution.hpp"

class Window {
public:
    Window(
        const std::string& title,
        Resolution resolution
    );

    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&&) noexcept;
    Window& operator=(Window&&) noexcept;

    void show();
    void clear();
    void present();
    void setColor(float x, float y, float z, float a);

    SDL_Renderer* getRenderer();
    SDL_Window* getWindow();
    float getScale();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    float mainScale;
};