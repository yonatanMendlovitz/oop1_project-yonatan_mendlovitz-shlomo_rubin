#ifndef BOMB_H
#define BOMB_H

#include "GameObject.h"
#include "MovableObject.h"
#include <SFML/System/Clock.hpp>
#include <vector>

class Bomb : public GameObject {
private:
    float elapsedTime = 0.0f;
    static constexpr float TIMER = 4.0f;
    bool exploded = 0;
    float explosionTime = 1.0f;
public:
    Bomb(const sf::Vector2f& pos, const sf::Vector2f& size);

    void update(float deltaTime);
    void explode(std::vector<std::unique_ptr<StaticObject>>& objects,
                 std::vector<std::unique_ptr<MovableObject>>& movables);

    virtual void handleCollision(GameObject& obj) override {}
    virtual void handleCollision(Guard& guard) override {}
    virtual void handleCollision(Wall& wall) override {}
    virtual void handleCollision(Player& player) override {}
    virtual void handleCollision(Stone& stone) override {}
    virtual void handleCollision(Door& door) override {}

    sf::FloatRect getBounds() const override { return m_sprite.getGlobalBounds(); }
    bool isExploded() {return exploded;};
};

#endif // BOMB_H
