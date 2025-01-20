#include "MovableObject.h"

MovableObject::MovableObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
    : GameObject(pos, size, texture), velocity(0), direction(0, 0) {
}

MovableObject::MovableObject(const MovableObject& other)
    : GameObject(other), velocity(other.velocity), direction(other.direction) {
}

MovableObject& MovableObject::operator=(const MovableObject& other) {
    if (this == &other) return *this;
    GameObject::operator=(other);
    velocity = other.velocity;
    direction = other.direction;
    return *this;
}

sf::Vector2f MovableObject::getDirection() const {
    return direction;
}

void MovableObject::setDirection(const sf::Vector2f& newDirection) {
    direction = newDirection;
}

void MovableObject::setVelocity(float newVelocity) {
    velocity = newVelocity;
}
