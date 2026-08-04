#pragma once

#include "../../../core/dataTipes/viewPort.hpp"

#include "../../../core/dataTipes/viewPort.hpp"

class Scene {
public:
    Scene();
    ~Scene() = default;

    void createScene();
    
    void setupScene(Viewport& viewport);
private:
    
    Viewport* viewport;
};