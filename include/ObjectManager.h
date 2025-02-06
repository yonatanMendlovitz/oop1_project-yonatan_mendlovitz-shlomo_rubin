#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>
#include "StaticObject.h"
#include "MovableObject.h"
#include "Player.h"
#include "Wall.h"
#include "Stone.h"
#include "Door.h"
#include "Bomb.h"
#include "Guard.h"

class ObjectManager {
public:
    ObjectManager(sf::RenderWindow& window);

    void loadObjects(const std::vector<std::string>& levelData, const sf::Vector2f& objectSize, const sf::Vector2f& boardOffset);
    void update(float deltaTime);
    void render() const;
    void updateSizes(const sf::Vector2f& newSize, const sf::Vector2f& boardOffset);

    void addMovable(std::unique_ptr<MovableObject> obj);
    Player* getPlayer() const;
    std::unique_ptr<Player> releasePlayer();
    bool isPlayerAtDoor() const;

private:
    sf::RenderWindow& m_window;
    std::vector<std::unique_ptr<StaticObject>> staticObjects;
    std::vector<std::unique_ptr<MovableObject>> movableObjects;
    std::vector<std::unique_ptr<Bomb>> bombs;
    sf::Vector2f m_boardOffset{ 0.0f, 0.0f };
};

#endif // OBJECT_MANAGER_H
