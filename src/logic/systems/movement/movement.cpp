#include "movement.hpp"

Movement::Movement() {}

void Movement::setSpeedX(float speedX){
    this->speedX = speedX;
}

void Movement::setSpeedY(float speedY){
    this->speedY = speedY;
}

void Movement::setDeltaTime(float deltaTime){
    this->deltaTime = deltaTime;
}

void Movement::moveRight(Collision& collision) {
    collision.setX(collision.getX() + deltaTime * speedX);
}

void Movement::moveLeft(Collision& collision) {
    collision.setX(collision.getX() - deltaTime * speedX);
}

void Movement::moveUp(Collision& collision) {
    collision.setY(collision.getY() - deltaTime * speedY);
}

void Movement::moveDown(Collision& collision) {
    collision.setY(collision.getY() + deltaTime * speedY);
}

float Movement::getSpeedX() {
    return speedX;
}

float Movement::getSpeedY() {
    return speedY;
}