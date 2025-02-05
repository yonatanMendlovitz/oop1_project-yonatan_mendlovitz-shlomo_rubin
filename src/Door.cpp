#include "Door.h"

Door::Door(const sf::Vector2f& position, const sf::Vector2f& size)
    : StaticObject(position, size, ResourceManager::getInstance().getTexture("door.png")) {
}

void Door::handleCollision(GameObject& obj) {
    obj.handleCollision(*this);
}

void Door::handleCollision(Player&) {
    // כאן נממש את הלוגיקה של מעבר לשלב הבא
    std::cout << "Player reached the door! Moving to the next level.\n";
}