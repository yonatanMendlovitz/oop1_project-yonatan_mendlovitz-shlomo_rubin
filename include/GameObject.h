// GameObject.h
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"ResourceManager.h"

class GameObject;
class Guard;
class Wall;
class Player;
class Bomb;
//class Stone;
//class gift;

class GameObject {
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::Sprite m_sprite;
	void updateSprite();
public:
	
	GameObject(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Texture& texture);
	GameObject(const GameObject& other); // Copy constructor
	GameObject& operator=(const GameObject& other); // Copy assignment operator
	virtual ~GameObject() = default;

	virtual void render(sf::RenderWindow& window) const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
	void setPosition(const sf::Vector2f& pos);
	void setSize(const sf::Vector2f& size);
	virtual sf::FloatRect getBounds() const = 0;

	virtual void handleCollision(GameObject&) = 0;
	virtual void handleCollision(Guard& ) = 0;
	virtual void handleCollision(Wall&) = 0;
	virtual void handleCollision(Player&) = 0;
	//virtual void handleCollision(Bomb&) = 0;
	//xyz
};


#endif // GAME_OBJECT_H

