// Bomb.h
#ifndef BOMB_H
#define BOMB_H

#include "StaticObject.h"
#include <vector>


class Bomb : public StaticObject {
private:
    float timer;

public:
    Bomb(const sf::Vector2f& pos, const sf::Vector2f& size); // loat timer, float radius, const sf::Texture& texture);
    Bomb(const Bomb& other); // Copy constructor
    Bomb& operator=(const Bomb& other); // Copy assignment operator
    void update(float deltaTime);
    void onPlayerCollision() override;
    bool isExploded() const;
};

#endif // BOMB_H
