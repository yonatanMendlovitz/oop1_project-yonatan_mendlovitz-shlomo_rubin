#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#pragma once
#include <vector>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "MovableObject.h"
#include "Player.h"
#include "Guard.h"
#include "Wall.h"
#include "Stone.h"
#include "Door.h"
#include "Bomb.h"
#include "CollisionHandler.h"

class LevelManager {
public:
    LevelManager(const std::string& filePath, std::unique_ptr<Player> player, sf::RenderWindow& window);
    std::unique_ptr<Player> run();

private:
    std::string levelFilePath;
    sf::RenderWindow& m_window;
    std::vector<std::unique_ptr<StaticObject>> staticObjects;
    std::vector<std::unique_ptr<MovableObject>> movableObjects;
    std::vector<std::unique_ptr<Bomb>> bombs;
    std::vector<std::string> levelData; 
    sf::Vector2f m_boardOffset{0.0f,0.0f};
    sf::Vector2f m_size{0.0f,0.0f};

    void loadLevel();
    void handleInput();
    void update(float deltaTime);
    void render();
    bool isLevelCompleted() const;
    sf::Vector2f calculateObjectSize() const;
    void updateObjectSizes();
};

#endif 
