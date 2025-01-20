#pragma once
#include "StaticObject.h"

class Wall : public StaticObject {
public:
    Wall(const sf::Vector2f& position, const sf::Vector2f& size);

    // Implement required function for player collision
    void onPlayerCollision() override;
};
