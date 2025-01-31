#include "LevelManager.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

LevelManager::LevelManager(const std::string& filePath, std::unique_ptr<Player> player, sf::RenderWindow& window)
	: levelFilePath(filePath), player(std::move(player)), m_window(window) {
	loadLevel();
}

void LevelManager::checkCollisions(MovableObject& movable) {
	for (const auto& staticObj : staticObjects)
		if (staticObj && movable.getBounds().intersects(staticObj->getBounds()))
			movable.handleCollision(*staticObj);
	if (movable.getBounds().intersects(player->getBounds()))
		player->handleCollision(movable);
}

void LevelManager::loadLevel() {
	std::ifstream inputFile(levelFilePath);
	if (!inputFile.is_open()) {
		throw std::runtime_error("Failed to open level file: " + levelFilePath);
	}

	staticObjects.clear();
	movableObjects.clear();

	std::string line;
	int row = 0;

	while (std::getline(inputFile, line)) {
		for (int col = 0; col < line.size(); ++col) {
			sf::Vector2f position(col * 100.0f, row * 100.0f);
			sf::Vector2f size(100.0f, 100.0f);

			switch (line[col]) {
			case WALL_SYMBOL:
				staticObjects.push_back(std::make_unique<Wall>(position, size));
				break;
			case GUARD_SYMBOL:
				movableObjects.push_back(std::make_unique<Guard>(position, size));
				break;
			case STONE_SYMBOL:
				staticObjects.push_back(std::make_unique<Stone>(position, size));
				break;
				//case GIFT_SYMBOL:  xyz
					//staticObjects.push_back(std::make_unique<Gift>(position, size));
			case PLAYER_SYMBOL:
				if (!player) {
					throw std::runtime_error("Player was not provided to LevelManager!");
				}
				player->setPosition(position);
				player->setSize(size);
				break;
			default:
				break;
			}
		}
		++row;
	}
}

std::unique_ptr<Player> LevelManager::run() {
	sf::Clock clock;

	while (m_window.isOpen() && player->getLives()) {
		float deltaTime = clock.restart().asSeconds();

		handleInput(m_window);
		update(deltaTime);
		render(m_window);
		for (auto& movable : movableObjects)
			checkCollisions(*movable);
		checkCollisions(*player);
		if (isLevelCompleted()) {
			break;
		}
	}
	return std::move(player);
}

void LevelManager::handleInput(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void LevelManager::update(float deltaTime) {
	if (player) {
		player->update(deltaTime);
	}
	for (auto& guard : movableObjects) {
		guard->update(deltaTime);
	}

	//CollisionHandler::checkCollisions(movableObjects, staticObjects);
}

void LevelManager::render(sf::RenderWindow& window) {
	window.clear();

	for (const auto& obj : staticObjects) {
		obj->render(window);
	}
	for (const auto& guard : movableObjects) {
		guard->render(window);
	}
	if (player) {
		player->render(window);
	}

	window.display();
}

bool LevelManager::isLevelCompleted() const {
	return false;
}
