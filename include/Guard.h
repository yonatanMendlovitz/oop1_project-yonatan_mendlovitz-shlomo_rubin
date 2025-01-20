#pragma once
#include "MovableObject.h"

class Guard : public MovableObject {
private:
    float patrolSpeed;      // Speed of guard during patrol
    sf::Vector2f patrolDirection; // Current direction of patrol

public:
    Guard(const sf::Vector2f& position, const sf::Vector2f& size);

    // Override update to handle guard-specific behavior
    void update(float deltaTime) override;

    // Handle collisions with other objects
    void onCollision(GameObject& other) override;

    // Set the patrol direction
    void setPatrolDirection(const sf::Vector2f& direction);

    // Get the patrol direction
    sf::Vector2f getPatrolDirection() const;
};
