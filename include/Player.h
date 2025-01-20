#ifndef PLAYER_H
#define PLAYER_H

#include "MovableObject.h"

class Player : public MovableObject {
private:
    int lives;
    int score;

public:
    Player(const sf::Vector2f& pos, const sf::Vector2f& size,  const sf::Texture& texture);
    Player(const sf::Vector2f& pos, const sf::Vector2f& size);
    void update(float deltaTime) override;
    void onCollision(GameObject& other) override;
    void onExplosionEffect();
    void addScore(int points);
    int getLives() const;
};

#endif // PLAYER_H
