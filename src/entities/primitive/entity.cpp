#include "entity.hpp"

Entity::Entity(): collision({0.0f,0.0f,0.0f,0.0f}), id(TexturesID::No_texture){
    
}

Entity::Entity(Collision collision, TexturesID id): collision(collision), id(id) {

}

Collision* Entity::getCollision() {
    return &collision;
}

const TexturesID Entity::getID() {
    return id;
}

const Rect Entity::getRect() {
    return collision.getRect();
}

void Entity::setTextureID(TexturesID id) {
    this->id = id;
}

void Entity::setCollision(Collision collision) {
    this->collision.setXY(collision.getX(), collision.getY());
    this->collision.setHeight(collision.getHeight());
    this->collision.setWidth(collision.getWidth());
}