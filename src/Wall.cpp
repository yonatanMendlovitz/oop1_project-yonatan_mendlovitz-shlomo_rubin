#include "Wall.h"
#include "ResourceManager.h"

Wall::Wall(const sf::Vector2f& position, const sf::Vector2f& size)
    : StaticObject(position, size, ResourceManager::getInstance().getTexture('#')) {
    // Load wall texture from the ResourceManager
    const sf::Texture& texture = ResourceManager::getInstance().getTexture("wall.png");
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Wall::onPlayerCollision() {
    // No special logic for player collision; simply block movement
    // This function can be extended for specific effects if needed
}
