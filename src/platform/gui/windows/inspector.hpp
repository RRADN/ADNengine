#pragma once

#include "../../../core/dataTipes/rect.hpp"

class Inspector {
public:
    Inspector();
    ~Inspector() = default;

    void setRect(Rect& rect);

    void createInspector();

private: 
    Rect* rect;

};