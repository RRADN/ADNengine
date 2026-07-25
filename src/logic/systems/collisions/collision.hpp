#pragma once 

#include <SDL3/SDL_rect.h>

class Collision {
public:
    Collision();
    Collision(float x, float y, float width, float height);
    ~Collision() = default;

    float getX() const { return x; }
    float getY() const { return y; }

    float getWidth() const { return width; }
    float getHeight() const { return height; }

    const SDL_FRect getRect();

    void setXY(float x, float y);
    void setX(float x);
    void setY(float y);

    void setWidth(float width);
    void setHeight(float height);

private:
    float x;
    float y;
    float width;
    float height;
    SDL_FRect rect;
};