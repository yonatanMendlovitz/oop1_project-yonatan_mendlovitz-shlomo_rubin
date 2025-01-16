#include "Player.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

// Custom operator for scaling sf::Vector2f
//sf::Vector2f operator*(const sf::Vector2f& vector, float scalar) {
//    return sf::Vector2f(vector.x * scalar, vector.y * scalar);
//}

Player::Player(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
    : MovableObject(pos, size, texture), lives(3), score(0) {
}

void Player::update(float deltaTime) {
    // Update position based on direction and velocity
    position += direction * velocity * deltaTime;
}

void Player::onCollision(GameObject& other) {
    // Handle collision logic with other objects
}

void Player::onExplosionEffect() {
    lives--;
    std::cout << "Player hit by explosion! Lives left: " << lives << "\n";
}

void Player::addScore(int points) {
    score += points;
}

int Player::getLives() const {
    return lives;
}
