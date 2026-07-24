#include "platform/window/sdlWindow.hpp"
#include "platform/events/sdlEvents.hpp"
#include "platform/rendering/renderManager.hpp"
#include "logic/input/inputManager.hpp"

int main() {
    Input input {};
    Window window {"ADNengine", {1280, 720}};
    Events events {};
    Render render {*window.getRenderer(), input.getSystemInputs(), {1280, 720}};

    while (events.update()) {
        window.clear();
        render.draw(ScreensID::Adn_white);
        window.present();
    }


}