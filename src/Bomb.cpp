#include "Bomb.h"
#include "Guard.h"
#include "Stone.h"
#include "MovableObject.h"

Bomb::Bomb(const sf::Vector2f& position, const sf::Vector2f& size)
	: GameObject(position, size, ResourceManager::getInstance().getTexture("bomb.png")) {
	const sf::Texture& texture = ResourceManager::getInstance().getTexture("bomb.png");
	m_sprite.setTexture(texture);
	setPosition(position);
}

void Bomb::update(float deltaTime) {
	elapsedTime += deltaTime;
	if (elapsedTime >= TIMER) {
		if (!exploded) {
			exploded = true;
			setPosition(m_position - m_size);
			setSize(m_size * 3.0f);
			m_sprite.setTexture(ResourceManager::getInstance().getTexture("Explosion.png"));
		}
		explosionTime -= deltaTime;
	}
	if (explosionTime <= 0)
		destroy();
}

void Bomb::explode(std::vector<std::unique_ptr<StaticObject>>& objects,
					std::vector<std::unique_ptr<MovableObject>>& movables) 
{
	for (auto& obj : objects)
		if (getBounds().intersects(obj->getBounds()))
			obj->onExplosion();


	for (auto& movable : movables)
		if (getBounds().intersects(movable->getBounds())) 
			movable->onExplosion();
}
