#include "DynamicObject.h"

DynamicObject::DynamicObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
    : GameObject(pos, size, texture), velocity(0), direction(0, 0) {
}

DynamicObject::DynamicObject(const DynamicObject& other)
    : GameObject(other), velocity(other.velocity), direction(other.direction) {
}

DynamicObject& DynamicObject::operator=(const DynamicObject& other) {
    if (this == &other) return *this;
    GameObject::operator=(other);
    velocity = other.velocity;
    direction = other.direction;
    return *this;
}

sf::Vector2f DynamicObject::getDirection() const {
    return direction;
}

void DynamicObject::setDirection(const sf::Vector2f& newDirection) {
    direction = newDirection;
}

void DynamicObject::setVelocity(float newVelocity) {
    velocity = newVelocity;
}
