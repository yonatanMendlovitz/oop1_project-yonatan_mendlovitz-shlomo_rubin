#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

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
#include "Bomb.h"
#include "Door.h"
#include "CollisionHandler.h"
#include "LevelTimer.h"

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
	sf::Vector2f m_boardOffset;
	sf::Vector2f m_size;
	LevelTimer levelTimer = LevelTimer(60.0f);
	void timeIsUp();
	void playerHurt();
	void loadLevel();
	void handleInput();
	void update(float deltaTime);
	void render();
	bool isLevelCompleted() const;
	sf::Vector2f calculateObjectSize() const;
	void updateObjectSizes();
};

#endif // LEVEL_MANAGER_H
