#include "GameObject.h"
#include <iostream>

//GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& size,const sf::Texture* texture): 
//    position(pos), size(size), 
//    sprite(sf::Sprite(*texture,sf::IntRect(sf::Vector2i(position), sf::Vector2i(size))))  {
//}
//GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
//	: position(pos), size(size) {
//	sprite.setTexture(texture);
//	sprite.setTextureRect(sf::IntRect(
//		static_cast<sf::Vector2i>(sf::Vector2f(position.x, position.y)),
//		static_cast<sf::Vector2i>(sf::Vector2f(size.x, size.y))
//	));
//	sprite.setPosition(position);
//
//}
GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
	: position(pos), size(size) {
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x), static_cast<int>(size.y)));
	sprite.setPosition(position);
}


GameObject::GameObject(const GameObject& other)
	: position(other.position), size(other.size), sprite(other.sprite) {
}

GameObject& GameObject::operator=(const GameObject& other) {
	if (this == &other) return *this;
	position = other.position;
	size = other.size;
	sprite = other.sprite;
	return *this;
}

void GameObject::render(sf::RenderWindow& window) const {

	std::cout << sprite.getPosition().x << ' ' << sprite.getPosition().y << '\n';
	window.draw(sprite);
}

sf::Vector2f GameObject::getPosition() const {
	return position;
}

sf::Vector2f GameObject::getSize() const {
	return size;
}

sf::FloatRect GameObject::getBounds() const {
	return sf::FloatRect(position, size);
}
