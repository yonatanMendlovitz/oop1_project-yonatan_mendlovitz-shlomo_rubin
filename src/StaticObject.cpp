// StaticObject.cpp
#include "StaticObject.h"

StaticObject::StaticObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture* texture)
    : GameObject(pos, size, texture) {
}

StaticObject::StaticObject(const StaticObject& other)
    : GameObject(other) {
}

StaticObject& StaticObject::operator=(const StaticObject& other) {
    if (this == &other) return *this;
    GameObject::operator=(other);
    return *this;
}
