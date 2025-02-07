#ifndef DOOR_H
#define DOOR_H

#include "StaticObject.h"
#include "Player.h"

class Door : public StaticObject {
public:
    Door(const sf::Vector2f& position, const sf::Vector2f& size);
    void handleCollision(GameObject&) override;
    void handleCollision(Player&) override;
    void handleCollision(Guard&) override {}
    void handleCollision(Wall&) override {}
    void handleCollision(Stone&) override {}
    void handleCollision(Door&) override {}
};

#endif // DOOR_H