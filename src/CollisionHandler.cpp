#include "CollisionHandler.h"

void CollisionHandler::checkCollisions(std::vector<std::unique_ptr<MovableObject>>& movables,
                                       std::vector<std::unique_ptr<StaticObject>>& statics) {
    for (auto& movable : movables) {
        for (auto& staticObj : statics) {
            if (movable->getBounds().intersects(staticObj->getBounds())) {
                movable->handleCollision(*staticObj);
            }
        }
    }
}

void CollisionHandler::checkMovableCollisions(std::vector<std::unique_ptr<MovableObject>>& movables) {
    for (size_t i = 0; i < movables.size(); ++i) {
        for (size_t j = i + 1; j < movables.size(); ++j) {
            if (movables[i]->getBounds().intersects(movables[j]->getBounds())) {
                movables[i]->handleCollision(*movables[j]);
                movables[j]->handleCollision(*movables[i]);// לבדוק האם צריך את שתי ההתנגשויות
            }
        }
    }
}
