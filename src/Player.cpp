#include "Player.h"



Player::Player(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
	: MovableObject(pos, size, texture), lives(3), score(0) {
	velocity = 100.0f;
}

Player::Player(const sf::Vector2f& pos, const sf::Vector2f& size) :
	Player(pos, size, ResourceManager::getInstance().getTexture("player.png")) {
}


//void Player::onCollision(GameObject& other) {
//
//}

void Player::onExplosionEffect() {
	lives--;
	//std::cout << "Player hit by explosion! Lives left: " << lives << "\n"; xyz
}

void Player::addScore(int points) {
	score += points;
}

int Player::getLives() const {
	return lives;
}

void Player::update(float deltaTime) {
	sf::Vector2f newPosition = m_position + (velocity * direction * deltaTime);
	if (newPosition.x > 0 && newPosition.x + m_size.x < 800 && newPosition.y > 0 && newPosition.y + m_size.y < 600)//xyz
	{
		setPosition(newPosition);
		return;
	}
	direction = sf::Vector2f(0, 0);
}

