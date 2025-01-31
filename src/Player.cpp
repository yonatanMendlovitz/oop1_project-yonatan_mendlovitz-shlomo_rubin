//

#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
    : MovableObject(pos, size, texture), lives(3), score(0) {
    velocity = baseSpeed;
}

Player::Player(const sf::Vector2f& pos, const sf::Vector2f& size)
    : MovableObject(pos, size, ResourceManager::getInstance().getTexture("player.png")), lives(3), score(0) {
    velocity = baseSpeed;
}

void Player::update(float deltaTime) {
    handleInput(); // Process input before updating position
    m_position += direction * velocity * deltaTime;
    updateSprite();
}

// 🕹️ Handles keyboard input
void Player::handleInput() {
    sf::Vector2f newDirection = sf::Vector2f(0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        newDirection = UP;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        newDirection = DOWN;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        newDirection = LEFT;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        newDirection = RIGHT;

    //Increase speed if moving in the same direction
    if (newDirection == direction)//xyz
        velocity += 1;
    else {
        velocity = baseSpeed; 
        direction = newDirection;
    }
}
