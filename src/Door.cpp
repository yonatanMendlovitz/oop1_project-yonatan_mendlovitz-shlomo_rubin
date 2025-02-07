#include "Door.h"

Door::Door(const sf::Vector2f& position, const sf::Vector2f& size)
	: StaticObject(position, size, ResourceManager::getInstance().getTexture("door.png")) {
}

void Door::handleCollision(GameObject& obj) {
	obj.handleCollision(*this);
}

void Door::handleCollision(Player& player) {
	player.handleCollision(*this);
}