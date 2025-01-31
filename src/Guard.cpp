#include "Guard.h"
#include "Stone.h"
#include "Player.h"
#include <iostream>
#include <cmath>

Guard::Guard(const sf::Vector2f& position, const sf::Vector2f& size)
    : MovableObject(position, size, ResourceManager::getInstance().getTexture(ENEMY_TEXTURE)) {
    velocity = BASE_SPEED * 0.8f;
    direction = RIGHT;
}

// ✅ Now we implement update(float deltaTime)
void Guard::update(float deltaTime) {
    sf::Vector2f newPosition = m_position + (velocity * direction * deltaTime);

    if (newPosition.x > 0 && newPosition.x + m_size.x < 800 && //xyz
        newPosition.y > 0 && newPosition.y + m_size.y < 600) {
        setPosition(newPosition);
    }
    else {
        setDirection(sf::Vector2f(-direction.x, -direction.y)); 
    }
}

// ✅ Update that considers player movement
void Guard::update(float deltaTime, const Player& player) {
    float distance = std::sqrt(
        std::pow(player.getPosition().x - m_position.x, 2) +
        std::pow(player.getPosition().y - m_position.y, 2)
    );

    if (distance < detectionRadius) {
        sf::Vector2f directionToPlayer = player.getPosition() - m_position;
        float length = std::sqrt(directionToPlayer.x * directionToPlayer.x + directionToPlayer.y * directionToPlayer.y);
        if (length != 0) {
            direction = sf::Vector2f(directionToPlayer.x / length, directionToPlayer.y / length);
        }
    }

    update(deltaTime); // ✅ Call default movement update
}

// Handles collisions with different objects
void Guard::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); }
void Guard::handleCollision(Guard& guard) {}
void Guard::handleCollision(Wall& wall) {
    separateFromStatic(wall);
    setDirection(sf::Vector2f(-direction.x, -direction.y));
}
void Guard::handleCollision(Player& player) { player.handleCollision(*this); }
void Guard::handleCollision(Stone& stone) {
    separateFromStatic(stone);
    setDirection(sf::Vector2f(-direction.x, -direction.y));
}
