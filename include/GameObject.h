// GameObject.h

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Sprite sprite;

public:
    GameObject(const sf::Vector2f& pos, const sf::Vector2f& size);
    virtual ~GameObject() = default;

    virtual void render(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    sf::FloatRect getBounds() const;
};

#endif