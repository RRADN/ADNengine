#include "sdlWindow.hpp"

#include <stdexcept>


Window::Window( const std::string& title, Resolution resolution) : sdl {} {
    
    window = SDL_CreateWindow(
        title.c_str(),
        resolution.width,
        resolution.height,
        SDL_WINDOW_BORDERLESS
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

    SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        0,
        0
    );
}

Window::~Window() {
    if (renderer)
        SDL_DestroyRenderer(renderer);

    if (window)
        SDL_DestroyWindow(window);

    sdl.~Context();
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