#pragma once

#include "../platform/context/contextManager.hpp"
#include "../platform/window/sdlWindow.hpp"
#include "../platform/gui/guiManager.hpp"
#include "../platform/events/eventsManager.hpp"

class ADN_ENGINE {
public:
    ADN_ENGINE();
    ~ADN_ENGINE() = default;

    void run();

private:
    bool done;

    void update();

    Context context {};

    Window window {"hola", {1280, 720}};

    GUI gui {window.getWindow(), window.getRenderer(), window.getScale()};

    Events events {};
};