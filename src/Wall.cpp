#include "Wall.h"
#include "Player.h"
#include "Guard.h"
#include "ResourceManager.h"



Wall::Wall(const sf::Vector2f& position, const sf::Vector2f& size)
	: StaticObject(position, size, ResourceManager::getInstance().getTexture('#')) {
	// Load wall texture from the ResourceManager
	//const sf::Texture& texture = ResourceManager::getInstance().getTexture("wall.png");
	//m_sprite.setTexture(texture);
	//m_sprite.setPosition(position);
}
void Wall::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); };
void Wall::handleCollision(Guard& guard) { guard.handleCollision(*this); };
void Wall::handleCollision(Wall& wall) {};
void Wall::handleCollision(Player& player) { player.handleCollision(*this); };
void Wall::handleCollision(Stone& stone) {};