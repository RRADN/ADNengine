#include "app.hpp"

ADN_ENGINE::ADN_ENGINE() {}

void ADN_ENGINE::run(){
    window.show();

    while (!done) {
        window.clear();

        ADN_ENGINE::update();
        
        window.present();
    }
}

void ADN_ENGINE::update() {
    done = events.update();

    gui.update();

}