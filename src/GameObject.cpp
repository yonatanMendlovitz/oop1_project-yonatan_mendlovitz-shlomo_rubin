#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& size)
    : position(pos), size(size) {
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
