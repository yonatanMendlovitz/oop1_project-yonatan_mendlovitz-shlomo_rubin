// StaticObject.h
#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "GameObject.h"

class StaticObject : public GameObject {
public:
    StaticObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture* texture);
    StaticObject(const StaticObject& other); // Copy constructor
    StaticObject& operator=(const StaticObject& other); // Copy assignment operator
    virtual ~StaticObject() = default;

    virtual void onPlayerCollision() = 0;
};

#endif // STATIC_OBJECT_H
