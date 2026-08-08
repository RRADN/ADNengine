#pragma once 

#include "../../../core/dataTipes/rect.hpp"

class Collision {
public:
    Collision();
    Collision(float x, float y, float width, float height);
    ~Collision() = default;

    float getX() const { return rect.x; }
    float getY() const { return rect.y; }

    float getWidth() const { return rect.width; }
    float getHeight() const { return rect.height; }

    Rect &getRect();

    void setXY(float x, float y);
    void setX(float x);
    void setY(float y);

    void setWidth(float width);
    void setHeight(float height);

private:
    Rect rect;
};