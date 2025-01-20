#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "GameObject.h"

class DynamicObject : public GameObject {
protected:
   float velocity;   // Speed of the object
    sf::Vector2f direction; // Direction of movement (normalized vector)

public:
    DynamicObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture);
    DynamicObject(const DynamicObject& other); // Copy constructor
    DynamicObject& operator=(const DynamicObject& other); // Copy assignment operator
    virtual ~DynamicObject() = default;

    virtual void update(float deltaTime) = 0;
    virtual void onCollision(GameObject& other) = 0;

    sf::Vector2f getDirection() const;
    void setDirection(const sf::Vector2f& newDirection);
    void setVelocity(float newVelocity);
};

#endif // MOVABLE_OBJECT_H
