#include "Guard.h"
#include "Player.h"
#include <iostream>

Guard::Guard(const sf::Vector2f& position, const sf::Vector2f& size)
	: MovableObject(position, size, ResourceManager::getInstance().getTexture("guard.png")), patrolSpeed(100.0f), patrolDirection(1.0f, 0.0f) {
}


//void Guard::onCollision(GameObject& other) {
//	std::cout << "Guard collided with another object!" << std::endl;
//}
//
//void Guard::setPatrolDirection(const sf::Vector2f& direction) {
//	patrolDirection = direction;
//}
//
//sf::Vector2f Guard::getPatrolDirection() const {
//	return patrolDirection;
//}

void Guard::update(float deltaTime) {
	sf::Vector2f newPosition = m_position + (velocity * direction * deltaTime);
	if (newPosition.x > 0 && newPosition.x + m_size.x < 800 && newPosition.y > 0 && newPosition.y + m_size.y < 600)//xyz
	{
		setPosition(newPosition);
		return;
	}
	direction = sf::Vector2f(-1 * direction.x, -1 * direction.y);
	return;
}

void Guard::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); };
void Guard::handleCollision(Guard& guard) {};
void Guard::handleCollision(Wall& wall) { setDirection(sf::Vector2f(-1 * direction.x, -1 * direction.y)); std::cout << "X\n"; };
void Guard::handleCollision(Player& player) { player.handleCollision(*this); };