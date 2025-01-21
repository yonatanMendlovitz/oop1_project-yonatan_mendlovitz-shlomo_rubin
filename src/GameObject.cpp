#include "GameObject.h"

// Constructor
GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture)
    : m_position(pos), m_size(size) {
    m_sprite.setTexture(texture);
    m_sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x), static_cast<int>(size.y)));
    m_sprite.setPosition(m_position);
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
    m_sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(m_size.x), static_cast<int>(m_size.y)));
    m_sprite.setPosition(m_position);
}

void GameObject::setPosition(const sf::Vector2f& pos) {
    m_position = pos;
    m_sprite.setPosition(pos);
}

void GameObject::setSize(const sf::Vector2f& size) {
    m_size = size;
    m_sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(size.x), static_cast<int>(size.y)));
}

//sf::FloatRect GameObject::getBounds() const {
//    return sf::FloatRect(m_position, m_size);
//}
