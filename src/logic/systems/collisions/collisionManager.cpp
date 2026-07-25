#include "collisionManager.hpp"

#include <algorithm>

CollisionManager::CollisionManager() {}

void CollisionManager::setNewCollision(Collision* collision){
    collisionMap.push_back(collision);
}

void CollisionManager::deleteCollision(Collision* collision) {
    auto it = std::find(collisionMap.begin(), collisionMap.end(), collision);

    if(it != collisionMap.end()){
        collisionMap.erase(it);
    }
}


bool CollisionManager::check(Collision& collision) {
    int x = collision.getX();
    int y = collision.getY();

    for(Collision* other : collisionMap)
    {
        if(other == &collision)
            continue;

        if(intersects(collision, *other))
        {
            return true;
        }
    }
    return false;
}

bool CollisionManager::intersects(Collision collision1, Collision collision2) {
    return  collision1.getX() < collision2.getX() + collision2.getWidth() &&
            collision1.getX() + collision1.getWidth() > collision2.getX() &&
            collision1.getY() < collision2.getY() + collision2.getHeight() &&
            collision1.getY() + collision1.getHeight() > collision2.getY();
}