#include "MovableObject.h"
#include <iostream>	

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
	velocity =/* newVelocity > maxVelocity ? maxVelocity :*/ newVelocity;//xyz
}



sf::FloatRect MovableObject::getBounds() const {
	return sf::FloatRect(m_position + (sf::Vector2f(m_size.x * 0.05f, m_size.y * 0.05f)), sf::Vector2f(m_size.x * 0.9f, m_size.y * 0.9f));
}

float MovableObject::getVelocity() const {
	std::cout << velocity << '\n';//xyz
	return velocity;
}