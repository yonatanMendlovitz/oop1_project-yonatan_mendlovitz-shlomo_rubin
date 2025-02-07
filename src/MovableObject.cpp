#include "MovableObject.h"
#include "StaticObject.h"
//#include <iostream>	
#include <algorithm> // For std::min

void MovableObject::separateFromStatic(const StaticObject& staticObject) {
	sf::FloatRect movableBounds = getBounds();
	sf::FloatRect staticBounds = staticObject.getBounds();

	// Check if there is an overlap
	if (movableBounds.intersects(staticBounds)) {
		// Calculate the amount of overlap in each direction
		float overlapLeft = movableBounds.left + movableBounds.width - staticBounds.left;
		float overlapRight = staticBounds.left + staticBounds.width - movableBounds.left;
		float overlapTop = movableBounds.top + movableBounds.height - staticBounds.top;
		float overlapBottom = staticBounds.top + staticBounds.height - movableBounds.top;

		// Determine the smallest overlap and move the object accordingly
		if (std::min(overlapLeft, overlapRight) < std::min(overlapTop, overlapBottom)) {
			// Horizontal adjustment
			if (overlapLeft < overlapRight) {
				m_position.x -= overlapLeft;
			}
			else {
				m_position.x += overlapRight;
			}
		}
		else {
			// Vertical adjustment
			if (overlapTop < overlapBottom) {
				m_position.y -= overlapTop;
			}
			else {
				m_position.y += overlapBottom;
			}
		}

		// Update the sprite position after adjustment
		//updateSprite();
	}
}

MovableObject::MovableObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
	: GameObject(pos, size, texture), velocity(0), direction(0, 0), initialPosition(pos) {
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
	return sf::FloatRect(m_position + (sf::Vector2f(m_size.x * 0.1f, m_size.y * 0.1f)), sf::Vector2f(m_size.x * 0.8f, m_size.y * 0.8f));
}

float MovableObject::getVelocity() const {
	//std::cout << velocity << '\n';//xyz
	return velocity;
}

//bool MovableObject::isAlive()
//{
//    return isAlive;
//}

void MovableObject::setInitialPosition(const sf::Vector2f& startPos) {
	initialPosition = startPos;
}

void MovableObject::resetPosition() {
	setPosition(initialPosition);
	isActive = true;
}