#include "platform/window/sdlWindow.hpp"
#include "platform/events/sdlEvents.hpp"
#include "platform/rendering/renderManager.hpp"
#include "logic/input/inputManager.hpp"

#include "entities/primitive/entity.hpp"

#include "core/ids/texturesID.hpp"

int main() {
    Input input {};
    Window window {"ADNengine", {1280, 720}};
    Events events {};
    Render render {*window.getRenderer(), input.getSystemInputs(), {1280, 720}};

    Entity entity {{0,0,100,100}, TexturesID::No_texture};

    while (events.update()) {
        window.clear();
        render.draw(ScreensID::Adn_white);
        render.draw(entity.getID(), entity.getRect());
        window.present();
    }
}