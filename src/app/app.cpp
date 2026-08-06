#include "app.hpp"

ADN_ENGINE::ADN_ENGINE() {
    viewport.texture = renderer.getViewportTexture();
    gui.setupScene(viewport);
}

void ADN_ENGINE::run(){
    window.show();

    while (!done) {
        window.clear();

        ADN_ENGINE::update();
        ADN_ENGINE::render();
        
        window.present();
    }
}

void ADN_ENGINE::update() {
    done = events.update();

    gui.update();

}

void ADN_ENGINE::render() {
    renderer.setRenderTarget();

    renderer.draw(ScreensID::Adn_black);

    renderer.setDefaultTarget();
}