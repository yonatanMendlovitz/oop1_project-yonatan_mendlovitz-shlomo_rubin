#include "Stone.h"
#include "Player.h"
#include "Guard.h"
#include "ResourceManager.h"



Stone::Stone(const sf::Vector2f& position, const sf::Vector2f& size)
	: StaticObject(position, size, ResourceManager::getInstance().getTexture("stone.png")) {
	// Load Stone texture from the ResourceManager
	//const sf::Texture& texture = ResourceManager::getInstance().getTexture("Stone.png");
	//m_sprite.setTexture(texture);
	//m_sprite.setPosition(position);
}
void Stone::handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); };
void Stone::handleCollision(Guard& guard) { guard.handleCollision(*this); };
void Stone::handleCollision(Wall& wall) {}
void Stone::handleCollision(Stone& stone) {}
void Stone::handleCollision(Player& player) { player.handleCollision(*this); }
void Stone::handleCollision(Door& door) {}