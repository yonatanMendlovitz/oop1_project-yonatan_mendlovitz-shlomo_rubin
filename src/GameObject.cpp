#include "GameObject.h"

// Constructor
GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
	: m_position(pos), m_size(size) {
	m_sprite.setTexture(texture);
	//m_sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x), static_cast<int>(size.y)));
	setPosition(m_position);
	setSize(size);
}

GameObject::GameObject(const GameObject& other)
	: m_position(other.m_position), m_size(other.m_size), m_sprite(other.m_sprite) {
}

GameObject& GameObject::operator=(const GameObject& other) {
	if (this == &other) return *this;
	m_position = other.m_position;
	m_size = other.m_size;
	m_sprite = other.m_sprite;
	return *this;
}

sf::Vector2f GameObject::getPosition() const {
	return m_position;
}

sf::Vector2f GameObject::getSize() const {
	return m_size;
}

void GameObject::render(sf::RenderWindow& window) const {
	window.draw(m_sprite);
}

void GameObject::updateSprite() {
	//setPosition(m_position);
	//setSize(m_size);
	//m_sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(m_size.x), static_cast<int>(m_size.y)));
	//m_sprite.setPosition(m_position);
}

void GameObject::setPosition(const sf::Vector2f& pos) {
	m_position = pos;
	m_sprite.setPosition(pos);
}

void GameObject::setSize(const sf::Vector2f& size) {
	m_size = size;
	if (m_sprite.getTexture()) { // בדיקה אם קיימת טקסטורה
		m_sprite.setScale(sf::Vector2f(
			m_size.x / m_sprite.getTexture()->getSize().x,
			m_size.y / m_sprite.getTexture()->getSize().y
		));
		//m_sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x), static_cast<int>(size.y)));
	}
}

//void GameObject::setSize(const sf::Vector2f& size) {
//    m_size = size;
//    if (m_sprite.getTexture()) {
//        sf::Vector2u textureSize = m_sprite.getTexture()->getSize();
//        m_sprite.setScale(
//            m_size.x / static_cast<float>(textureSize.x),
//            m_size.y / static_cast<float>(textureSize.y)
//        );
//    }
//}