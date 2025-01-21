#ifndef PLAYER_H
#define PLAYER_H

#include "MovableObject.h"
#include "Stone.h"
#include "Wall.h"

class Player : public MovableObject {
private:
	int lives;
	int score;

public:
	Player(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture);
	Player(const sf::Vector2f& pos, const sf::Vector2f& size);
	void update(float deltaTime) override;
	//void onCollision(GameObject& other) override;
	void onExplosionEffect();
	void addScore(int points);
	int getLives() const;
	//void youShallNotPass() override;

	virtual void  handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); }
	virtual void handleCollision(Guard& guard) { std::cout << "player is dead :(\n"; };
	virtual void handleCollision(Player&) {};
	virtual void handleCollision(Stone& stone) { separateFromStatic(stone); direction = sf::Vector2f(0, 0); };
	virtual void handleCollision(Wall& wall) { separateFromStatic(wall); direction = sf::Vector2f(0, 0); };

};

#endif // PLAYER_H
