// GameObject.cpp
#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& size,const sf::Texture& texture): 
    position(pos), size(size), 
    sprite(sf::Sprite(texture,sf::IntRect(sf::Vector2i(position), sf::Vector2i(size))))  {
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
