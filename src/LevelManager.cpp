#include <string>
#include <fstream>
#include <iostream>
#include "GameManager.h"
#include "LevelManager.h"

LevelManager::LevelManager(const std::string& filePath, std::unique_ptr<Player> player, sf::RenderWindow& window)
	: levelFilePath(filePath), m_window(window) {
	movableObjects.push_back(std::move(player)); // מוסיף את השחקן ראשון
	loadLevel();
}

void LevelManager::loadLevel() {
	std::ifstream inputFile(levelFilePath);
	if (!inputFile.is_open())
		throw std::runtime_error("Failed to open level file: " + levelFilePath);

	levelData.clear(); // מנקה נתונים ישנים

	std::string line;
	while (std::getline(inputFile, line))
		levelData.push_back(line);

	if (levelData.empty()) {
		throw std::runtime_error("Error: Level file is empty!");
	}

	sf::Vector2f size = calculateObjectSize();
	m_boardOffset = sf::Vector2f(
		(m_window.getSize().x - (size.x * levelData.at(0).size())) / 2.0f,  // היסט אופקי
		(m_window.getSize().y - (size.y * levelData.size())) / 2.0f         // היסט אנכי
	);

	for (int row = 0; row < levelData.size(); row++) {
		for (int col = 0; col < levelData[row].size(); ++col) {  // משתמש בגודל האמיתי של השורה
			sf::Vector2f position(col * size.x, row * size.y);
			position += m_boardOffset; // הזזה למרכז המסך

			switch (levelData[row][col]) {
			case '#':
				staticObjects.push_back(std::make_unique<Wall>(position, size));
				break;
			case '!':
				movableObjects.push_back(std::make_unique<Guard>(position, size));
				break;
			case '@':
				staticObjects.push_back(std::make_unique<Stone>(position, size));
				break;
			case 'D':
				staticObjects.push_back(std::make_unique<Door>(position, size));
				break;
			case '/':
				if (!movableObjects.empty()) {
					movableObjects.at(0)->setPosition(position);
					movableObjects.at(0)->setSize(size);
				}
				break;
			}
		}
	}
}

std::unique_ptr<Player> LevelManager::run() {
	sf::Clock clock;

	while (m_window.isOpen() && movableObjects.at(0)->isAlive()) {
		float deltaTime = clock.restart().asSeconds();
		handleInput();
		update(deltaTime);
		render();

		if (isLevelCompleted()) {
			break;
		}
	}
	return std::unique_ptr<Player>(static_cast<Player*>(movableObjects.at(0).release()));
}

void LevelManager::handleInput() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			m_window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			dynamic_cast<Player*>(movableObjects.at(0).get())->placeBomb(bombs);
		if (event.type == sf::Event::Resized) {
			updateObjectSizes();
		}
	}
}

void LevelManager::update(float deltaTime) {
	bombs.erase(std::remove_if(bombs.begin(), bombs.end(), [](const std::unique_ptr<Bomb>& bomb) { return !bomb->isAlive(); }), bombs.end());
	movableObjects.erase(std::remove_if(movableObjects.begin(), movableObjects.end(), [](const std::unique_ptr<MovableObject>& movable) { return !movable->isAlive(); }), movableObjects.end());
	staticObjects.erase(std::remove_if(staticObjects.begin(), staticObjects.end(), [](const std::unique_ptr<StaticObject>& obj) { return !obj->isAlive(); }), staticObjects.end());

	for (auto& movable : movableObjects)
		movable->update(deltaTime);
	for (auto& bomb : bombs) {
		bomb->update(deltaTime);
		if (bomb->isExploded())
			bomb->explode(staticObjects, movableObjects);
	}

	CollisionHandler::checkCollisions(movableObjects, staticObjects);
	CollisionHandler::checkMovableCollisions(movableObjects);
}

void LevelManager::render() {
	m_window.clear(sf::Color::Magenta);
	for (const auto& obj : staticObjects) obj->render(m_window);
	for (const auto& movable : movableObjects) movable->render(m_window);
	for (const auto& bomb : bombs) bomb->render(m_window);
	m_window.display();
}

bool LevelManager::isLevelCompleted() const {
	return false; // לעתיד: בדיקה אם השחקן עבר שלב
}

sf::Vector2f LevelManager::calculateObjectSize() const {
	if (levelData.empty()) return sf::Vector2f(50.f, 50.f); // ברירת מחדל אם אין נתונים

	float cellWidth = m_window.getSize().x / static_cast<float>(levelData.at(0).size());
	float cellHeight = m_window.getSize().y / static_cast<float>(levelData.size());
	float squareSize = std::min(cellWidth, cellHeight);
	return sf::Vector2f(squareSize, squareSize);
}

void LevelManager::updateObjectSizes() {
	if (levelData.empty()) return;
	// חישוב גודל חדש לאובייקטים
	sf::Vector2f newSize = calculateObjectSize();

	// חישוב היסט מרכזי
	m_boardOffset = sf::Vector2f(
		(m_window.getSize().x - (levelData.at(0).size() * newSize.x)) / 2.0f,
		(m_window.getSize().y - (levelData.size() * newSize.y)) / 2.0f
	) - m_boardOffset;

	// עדכון אובייקטים נייחים
	for (auto& obj : staticObjects) {
		sf::Vector2f normalizedPos = obj->getPosition();
		normalizedPos.x = (normalizedPos.x / obj->getSize().x) * newSize.x + m_boardOffset.x;
		normalizedPos.y = (normalizedPos.y / obj->getSize().y) * newSize.y + m_boardOffset.y;

		obj->setSize(newSize);
		obj->setPosition(normalizedPos);
	}

	// עדכון אובייקטים ניידים (אם יש צורך)
	for (auto& obj : movableObjects) {
		sf::Vector2f normalizedPos = obj->getPosition();
		normalizedPos.x = (normalizedPos.x / obj->getSize().x) * newSize.x + m_boardOffset.x;
		normalizedPos.y = (normalizedPos.y / obj->getSize().y) * newSize.y + m_boardOffset.y;

		obj->setSize(newSize);
		obj->setPosition(normalizedPos);
	}

	for (auto& bomb : bombs) {
		sf::Vector2f newPos = bomb->getPosition();
		newPos.x = (newPos.x / bomb->getSize().x) * newSize.x + m_boardOffset.x;
		newPos.y = (newPos.y / bomb->getSize().y) * newSize.y + m_boardOffset.y;

		bomb->setSize(newSize);
		bomb->setPosition(newPos);
	}
}


