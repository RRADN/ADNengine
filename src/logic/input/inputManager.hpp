#pragma once

#include "../../core/dataTipes/inputs.hpp"
#include "keysManager.hpp"

class Input {
public: 
    Input();
    ~Input() = default;

    void update();

    SystemInputs& getSystemInputs();
    GameInputs& getGameInputs();
    
    bool enter() {return systemInputs.run;};
    void enterReset() {systemInputs.run = false;}

private:
    void systemUpdate();
    void gameUpdate();

    Keys keys {};

    SystemInputs systemInputs {};
    GameInputs gameInputs {};
    
};