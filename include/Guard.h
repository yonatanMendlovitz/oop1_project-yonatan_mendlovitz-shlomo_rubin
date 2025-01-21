#pragma once
#include "MovableObject.h"

class Guard : public MovableObject {
private:
	float patrolSpeed;      // Speed of guard during patrol
	sf::Vector2f patrolDirection; // Current direction of patrol

public:
	Guard(const sf::Vector2f& position, const sf::Vector2f& size);
	//void onCollision(GameObject& other) override;
	//void setPatrolDirection(const sf::Vector2f& direction);
	//sf::Vector2f getPatrolDirection() const;
	void handleCollision(GameObject& gameObject) override;
	void handleCollision(Guard& guard)override;
	void handleCollision(Wall& wall) override;
	void handleCollision(Player& player) override;
	sf::FloatRect getBounds() const override { return m_sprite.getGlobalBounds(); }//xyz

	void update(float deltaTime) override;
};
