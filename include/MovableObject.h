#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "GameObject.h"
class StaticObject;

class MovableObject : public GameObject {
protected:
    sf::Vector2f initialPosition;
    float velocity;
    sf::Vector2f direction; // Direction of movement (normalized vector)

public:
    MovableObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture);
    MovableObject(const MovableObject& other); // Copy constructor
    MovableObject& operator=(const MovableObject& other); // Copy assignment operator
    virtual ~MovableObject() = default;
    void separateFromStatic(const StaticObject& staticObject);
    sf::FloatRect getBounds() const override;
    sf::Vector2f getDirection() const;
    void setDirection(const sf::Vector2f& newDirection);
    void setVelocity(float newVelocity);
    float getVelocity() const;
    virtual void update(float deltaTime) = 0;
    virtual void die() = 0;
    void setInitialPosition(const sf::Vector2f& startPos);
    void resetPosition();
};

#endif // MOVABLE_OBJECT_H
