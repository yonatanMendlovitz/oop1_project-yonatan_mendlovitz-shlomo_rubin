#pragma once
#include "StaticObject.h"

class GameObject;
class Guard;
//class Wall;
class Player;
class Bomb;

class Wall : public StaticObject {
public:
	Wall(const sf::Vector2f& position, const sf::Vector2f& size);

	// Implement required function for player collision
	//void onPlayerCollision() override;
    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Guard& guard)override;
    void handleCollision(Wall& wall) override;
    void handleCollision(Player& player) override;

};
