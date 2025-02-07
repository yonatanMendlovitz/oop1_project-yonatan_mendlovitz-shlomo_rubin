#include "Player.h"
#include "ResourceManager.h"
#include <cmath>

Player::Player(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
	: MovableObject(pos, size, texture), lives(3), score(0) {
	velocity = baseSpeed;
}

Player::Player(const sf::Vector2f& pos, const sf::Vector2f& size)
	: MovableObject(pos, size, ResourceManager::getInstance().getTexture(PLAYER_TEXTURE)), lives(3), score(0) {
	velocity = baseSpeed;
	std::cout << m_sprite.getTexture()->getSize().x << '\n';
}

void Player::update(float deltaTime) {
	handleInput();
	setPosition(m_position + direction * velocity * deltaTime);//
}

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


void Player::placeBomb(std::vector<std::unique_ptr<Bomb>>& bombs) {
	sf::Vector2f bombPosition(
		std::round(getPosition().x / m_size.x) * m_size.x,
		std::round(getPosition().y / m_size.y) * m_size.y
	);

	for (const auto& bomb : bombs) {
		if (bomb->getPosition() == bombPosition) {
			std::cout << "Bomb already exists at this position.\n";
			return;
		}
	}

	bombs.emplace_back(std::make_unique<Bomb>(bombPosition, m_size));
	std::cout << "Bomb placed at: " << bombs.at(bombs.size() - 1)->getPosition().x << ", " << bombs.at(bombs.size() - 1)->getPosition().y << '\n';
}

void Player::die() {
	destroy(); lives--;
	ResourceManager::getInstance().playSound("death.wav");
};

void Player::resetPosition() {
	setPosition(initialPosition);
	isActive = lives > 0;
}

void Player::setLevelCompleted(bool completed) {
	levelCompleted = completed;
}

bool Player::hasCompletedLevel() const {
	return levelCompleted;
}

