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

    Viewport viewport {nullptr, configs.HD, configs.HD};

    bool done;

    void update();
    void render();

    Context context {};

    Window window {"ADN_ENGINE", viewport.windowResolution};

    Render renderer {window.getRenderer(), input.getSystemInputs()};

    GUI gui {window.getWindow(), window.getRenderer(), window.getScale()};

    Events events {};
};