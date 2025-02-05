#pragma once
#include "StaticObject.h"

class GameObject;
class Guard;
//class Stone;
class Player;
class Bomb;

class Stone : public StaticObject {
public:
    Stone(const sf::Vector2f& position, const sf::Vector2f& size);

    // Implement required function for player collision
    //void onPlayerCollision() override;
    void onExplosion() override { destroy(); } // סלע נהרס בפיצוץ

    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Guard& guard)override;
    void handleCollision(Wall& wall) override;
    void handleCollision(Stone& stone) override;
    void handleCollision(Player& player) override;

};