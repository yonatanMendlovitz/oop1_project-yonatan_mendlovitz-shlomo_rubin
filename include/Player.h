//#ifndef PLAYER_H
//#define PLAYER_H
//
//#include "MovableObject.h"
//#include "Stone.h"
//#include "Wall.h"
//
//class Player : public MovableObject {
//private:
//	int lives;
//	int score;
//
//public:
//	Player(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture);
//	Player(const sf::Vector2f& pos, const sf::Vector2f& size);
//	void update(float deltaTime) override;
//	//void onCollision(GameObject& other) override;
//	void onExplosionEffect();
//	void addScore(int points);
//	int getLives() const;
//	//void youShallNotPass() override;
//
//	virtual void  handleCollision(GameObject& gameObject) { gameObject.handleCollision(*this); }
//	virtual void handleCollision(Guard& guard) { std::cout << "player is dead :(\n"; };
//	virtual void handleCollision(Player&) {};
//	virtual void handleCollision(Stone& stone) { separateFromStatic(stone); direction = sf::Vector2f(0, 0); };
//	virtual void handleCollision(Wall& wall) { separateFromStatic(wall); direction = sf::Vector2f(0, 0); };
//
//};
//
//#endif // PLAYER_H



#ifndef PLAYER_H
#define PLAYER_H

#include "MovableObject.h"
#include "Stone.h"
#include "Wall.h"

class Player : public MovableObject {
private:
    int lives;
    int score;
    const float baseSpeed = 100.0f;

public:
    Player(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture);
    Player(const sf::Vector2f& pos, const sf::Vector2f& size);

    void update(float deltaTime) override;
    void handleInput(); // Handles keyboard input

    void onExplosionEffect();
    void addScore(int points);
    int getLives() const;
    
    void die() override { iAmAlive = false;  lives--; };
    void handleCollision(GameObject& gameObject) override { gameObject.handleCollision(*this); }
    void handleCollision(Guard& guard) override { std::cout << "player is dead :(\n"; die(); };
    void handleCollision(Player&) override {};
    void handleCollision(Stone& stone) override { separateFromStatic(stone); direction = sf::Vector2f(0, 0); };
    void handleCollision(Wall& wall) override { separateFromStatic(wall); direction = sf::Vector2f(0, 0); };
};

#endif // PLAYER_H
