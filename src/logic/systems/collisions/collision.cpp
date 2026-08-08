#include "collision.hpp"

Collision::Collision(){}

Collision::Collision(float x, float y, float width, float height) {
    this->rect.x = x;
    this->rect.y = y;
    this->rect.width = width;
    this->rect.height = height;
}

Rect &Collision::getRect() {
    return rect;
}

void Collision::setXY(float x, float y){
    this->rect.x = x;
    this->rect.y = y;
}

void Collision::setX(float x){
    this->rect.x = x;
}

void Collision::setY(float y){
    this->rect.y = y;
}

void Collision::setWidth(float width) {
    this->rect.width = width;
}

void Collision::setHeight(float height) {
    this->rect.height = height;
}