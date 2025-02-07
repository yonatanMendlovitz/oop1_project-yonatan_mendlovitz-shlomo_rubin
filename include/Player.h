#ifndef PLAYER_H
#define PLAYER_H

#include "MovableObject.h"
#include "StaticObject.h"
#include "Stone.h"
#include "Wall.h"
#include "Bomb.h"
#include "Guard.h"

class Player : public MovableObject {
private:
	int lives;
	int score;
	const float baseSpeed = 100.0f;
	bool levelCompleted = false;

public:
	Player(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture);
	Player(const sf::Vector2f& pos, const sf::Vector2f& size);

	void update(float deltaTime) override;
	void handleInput(); // Handles keyboard input

	void onExplosionEffect();
	void addScore(int points);
	int  getLives() const { return lives; };
	void placeBomb(std::vector<std::unique_ptr<Bomb>>& objects);
	void onExplosion() override { die(); };
	void die() override;
	void handleCollision(GameObject& gameObject) override { gameObject.handleCollision(*this); }
	void handleCollision(Guard& guard) override { if (!isAlive()) return; die(); };
	void handleCollision(Player&) override {};
	void handleCollision(Door& door) override { setLevelCompleted(true); };
	void handleCollision(Stone& stone) override { separateFromStatic(stone); direction = sf::Vector2f(0, 0); };
	void handleCollision(Wall& wall) override { separateFromStatic(wall); direction = sf::Vector2f(0, 0); };
	void resetPosition() override;
	void setLevelCompleted(bool completed);
	bool hasCompletedLevel() const;        


};

#endif // PLAYER_H

//#pragma once
//#include "MovableObject.h"
//#include "Constants.h"
//
//class Guard : public MovableObject {
//private:
//	float detectionRadius = 300.0f; // Distance at which the guard detects the player
//
//public:
//	Guard(const sf::Vector2f& position, const sf::Vector2f& size);
//
//	void update(float deltaTime) override;
//	void update(float deltaTime, const Player& player);
//
//	void changeDirection();
//
//	void handleCollision(GameObject& gameObject) override;
//	void handleCollision(Guard& guard) override;
//	void handleCollision(Wall& wall) override;
//	void handleCollision(Player& player) override;
//	void handleCollision(Stone& stone) override;
//	void die() override { destroy(); };
//	sf::FloatRect getBounds() const override { return m_sprite.getGlobalBounds(); }
//};
