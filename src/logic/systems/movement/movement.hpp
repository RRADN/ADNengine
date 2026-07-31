#pragma once 

#include "../collisions/collision.hpp"

class Movement {
public:
    Movement();
    ~Movement() = default;

    void setSpeedX(float speed);
    void setSpeedY(float speed);
    
    void setDeltaTime(float deltaTime);
    
    void moveRight(Collision& collision);
    void moveLeft (Collision& collision);
    void moveUp   (Collision& collision);
    void moveDown (Collision& collision);

    float getSpeedX();
    float getSpeedY();
    
private:
    float speedX;
    float speedY;
    float deltaTime;
};
