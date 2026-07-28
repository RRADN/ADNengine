#include "sdlWindow.hpp"

#include <stdexcept>


Window::Window( const std::string& title, Resolution resolution) {
    mainScale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
    SDL_WindowFlags windowFlags = SDL_WINDOW_BORDERLESS | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;
    window = SDL_CreateWindow(
        title.c_str(),
        resolution.width,
        resolution.height,
        windowFlags
    );

    if (!window)
        throw std::runtime_error(SDL_GetError());

    renderer = SDL_CreateRenderer(
        window,
        nullptr
    );

    if (!renderer)
    {
        SDL_DestroyWindow(window);
        throw std::runtime_error(SDL_GetError());
    }

    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

}

Window::~Window() {
    if (renderer)
        SDL_DestroyRenderer(renderer);

    if (window)
        SDL_DestroyWindow(window);
}

void Window::show() {
    SDL_ShowWindow(window);
}

void Window::clear() {
    SDL_RenderClear(renderer);
}

void Window::present() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Window::getRenderer() {
    return renderer;
}

SDL_Window* Window::getWindow() {
    return window;
}

float Window::getScale() {
    return mainScale;
}