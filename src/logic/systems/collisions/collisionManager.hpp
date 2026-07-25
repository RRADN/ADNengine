#pragma once

#include <vector>
#include "collision.hpp"

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager() = default;

    void setNewCollision(Collision* newCollision);
    void deleteCollision(Collision* oldCollision);

    bool check(Collision& collision);

private:    
    bool intersects(Collision collision1, Collision collision2);

    std::vector<Collision*> collisionMap;
};