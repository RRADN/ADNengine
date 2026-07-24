#pragma once

#include <SDL3/SDL.h>
#include <string>

#include "sdlContext.hpp"

#include "../../core/config/resolution.hpp"

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

    void clear();
    void present();

    SDL_Renderer* getRenderer();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    Context sdl;

    int width;
    int height;
};