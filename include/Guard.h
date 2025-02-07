#pragma once
#include "MovableObject.h"
#include "Constants.h"

class Guard : public MovableObject {
private:
    float detectionRadius = 300.0f; // Distance at which the guard detects the player

public:
    Guard(const sf::Vector2f& position, const sf::Vector2f& size);

    void update(float deltaTime) override;
    void update(float deltaTime, const Player& player);

    void changeDirection();

    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Guard& guard) override;
    void handleCollision(Wall& wall) override;
    void handleCollision(Player& player) override;
    void handleCollision(Stone& stone) override;
    void resetPosition() override;
    void die() override { destroy(); };
    void onExplosion() override { destroy(); } 

    sf::FloatRect getBounds() const override { return m_sprite.getGlobalBounds(); }
};
