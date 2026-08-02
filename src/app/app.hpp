#pragma once

#include "../platform/context/contextManager.hpp"
#include "../platform/window/sdlWindow.hpp"
#include "../platform/rendering/renderManager.hpp"
#include "../platform/gui/guiManager.hpp"
#include "../platform/events/eventsManager.hpp"

#include "../core/config/configs.hpp"

#include "../logic/input/inputManager.hpp"

class ADN_ENGINE {
public:
    ADN_ENGINE();
    ~ADN_ENGINE() = default;

    void run();

private:
    Configs configs {};

    Input input {};

    bool done;

    void update();

    Context context {};

    Window window {"hola", {1280, 720}};

    Render renderer {*window.getRenderer(), input.getSystemInputs()};

    GUI gui {window.getWindow(), window.getRenderer(), window.getScale()};

    Events events {};
};