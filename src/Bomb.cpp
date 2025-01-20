// Bomb.cpp
#include "Bomb.h"
#include <cmath>
#include <iostream>

Bomb::Bomb(const sf::Vector2f& pos, const sf::Vector2f& size)//, float timer, float radius, const sf::Texture& texture)
    : StaticObject(pos, size, ResourceManager::getInstance().getTexture("Bomb.png"))//, timer(timer){
{}

Bomb::Bomb(const Bomb& other)
    : StaticObject(other), timer(other.timer) {
}

Bomb& Bomb::operator=(const Bomb& other) {
    if (this == &other) return *this;
    StaticObject::operator=(other);
    //timer = other.timer;
    return *this;
}

void Bomb::update(float deltaTime) {
    timer -= deltaTime;
    if (timer <= 0) {
        // Explosion logic
    }
}

void Bomb::onPlayerCollision() {
    // Interaction logic if needed
}

bool Bomb::isExploded() const {
    return timer <= 0;
}