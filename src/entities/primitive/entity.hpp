#pragma once

//systems
#include "../../logic/systems/collisions/collision.hpp"
//id
#include "../../core/ids/texturesID.hpp"

class Entity {
public:
    Entity();
    Entity(Collision collision, TexturesID id);
    ~Entity() = default;

    Rect& getRect();
    const TexturesID getID();
    Collision* getCollision();

    void setTextureID(TexturesID id);
    void setCollision(Collision collision);

private:
    TexturesID id;
    Collision collision;

};