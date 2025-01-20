#include "Guard.h"
#include <iostream>

Guard::Guard(const sf::Vector2f& position, const sf::Vector2f& size)
    : MovableObject(position, size, ResourceManager::getInstance().getTexture("guard.png")), patrolSpeed(100.0f), patrolDirection(1.0f, 0.0f) {
    // Load the guard texture from the ResourceManager
   /* const sf::Texture& texture = ResourceManager::getInstance().getTexture("guard.png");
    sprite.setTexture(texture);
    sprite.setPosition(position);*/
}

void Guard::update(float deltaTime) {
    // Patrol logic: move in the current direction
    position += patrolDirection * patrolSpeed * deltaTime;
    sprite.setPosition(position);

    // Example patrol boundary logic
    if (position.x < 0 || position.x  > 800) { // Assuming screen width is 800
        patrolDirection.x *= -1; // Reverse direction
    }
    if (position.y < 0 || position.y > 600) { // Assuming screen height is 600
        patrolDirection.y *= -1; // Reverse direction
    }
}

void Guard::onCollision(GameObject& other) {
    // Example collision logic
    std::cout << "Guard collided with another object!" << std::endl;
}

void Guard::setPatrolDirection(const sf::Vector2f& direction) {
    patrolDirection = direction;
}

sf::Vector2f Guard::getPatrolDirection() const {
    return patrolDirection;
}
