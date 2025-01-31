#pragma once
#include <vector>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Guard.h"
#include "Wall.h"
#include "Stone.h"
#include "Player.h"
//#include "CollisionHandler.h"

class LevelManager {
public:
    LevelManager(const std::string& filePath, std::unique_ptr<Player> player, sf::RenderWindow& window);
    std::unique_ptr<Player> run();

private:
    std::string levelFilePath;
    std::vector<std::unique_ptr<StaticObject>> staticObjects;
    std::vector<std::unique_ptr<MovableObject>> movableObjects;
    std::unique_ptr<Player> player;
    sf::RenderWindow& m_window;
    void checkCollisions(MovableObject& movable);
    void loadLevel();
    void handleInput(sf::RenderWindow& window);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    bool isLevelCompleted() const;
};
