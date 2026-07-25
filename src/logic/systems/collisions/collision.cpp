#include "collision.hpp"

Collision::Collision(){}

Collision::Collision(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

const SDL_FRect Collision::getRect() {
    rect = {x, y, width, height};
    return rect;
}

void Collision::setXY(float x, float y){
    this->x = x;
    this->y = y;
}

void Collision::setX(float x){
    this->x = x;
}

void Collision::setY(float y){
    this->y = y;
}

void Collision::setWidth(float width) {
    this->width = width;
}

void Collision::setHeight(float height) {
    this->height = height;
}