#include <SDL3/SDL.h>

#include "platform/context/contextManager.hpp"
#include "platform/window/sdlWindow.hpp"
#include "platform/events/eventsManager.hpp"
#include "platform/gui/guiManager.hpp"

int main() {
    bool done = false;

    Context context {};

    Window window {"hola", {1280, 720}};

    GUI gui {window.getWindow(), window.getRenderer(), window.getScale()};

    Events events {};
    
    window.show();

    while (!done) {
        done = events.update();

        window.clear();

        gui.update();
        
        window.present();
    }
    return 0;
}
