#include "ObjectManager.h"
#include "Wall.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

ObjectManager::ObjectManager(const std::string& levelFilePath, int startingLives, int startingScore, Player* player)
    : lives(startingLives), score(startingScore), player(player) {
    std::ifstream inputFile(levelFilePath);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open level file: " + levelFilePath);
    }
    initBoard(inputFile);

    gameBoard.setTexture(&ResourceManager::getInstance().getTexture("gameImage.jpeg"));
    gameBoard.setSize(sf::Vector2f(600, 400)); // Initial size
    gameBoard.setPosition(100, 100);          // Centered in the window
}

void ObjectManager::initBoard(std::ifstream& inputFile) {
    std::string line;
    int row = 0;

    while (std::getline(inputFile, line)) {
        for (int col = 0; col < line.size(); ++col) {
            char tile = line[col];
            switch (tile) {
            case '#': // Wall
                m_board.push_back(std::make_unique<Wall>(sf::Vector2f(col * 100, row * 100), sf::Vector2f(100, 100)));
                break;
            case '@':
                m_board.push_back(std::make_unique<Stone>(sf::Vector2f(col * 100, row * 100), sf::Vector2f(100, 100)));
                break;

            case '/': // Player
                player->setPosition(sf::Vector2f(col * 100, row * 100));
                player->setSize(sf::Vector2f(100, 100));
                player->setDirection(sf::Vector2f(1, 0));
                player->setVelocity(180);
                break;

            case '!': // Enemy (Guard)
                guards.push_back(std::make_unique<Guard>(sf::Vector2f(col * 100, row * 100), sf::Vector2f(100, 100)));
                guards.back()->setDirection(sf::Vector2f(0, 1));
                guards.back()->setVelocity(120);
                break;

            case ' ': // Empty space
            default:
                break;
            }
        }
        ++row;
    }
}

void ObjectManager::addBomb(sf::Vector2f position, float timer, float radius) {
    // Implement logic to add bombs if needed
}

void ObjectManager::update(float deltaTime) {
    // Update player and check collisions
    if (player) {
        player->update(deltaTime);
        checkCollisions(*player);
    }

    // Update guards and check collisions
    for (auto& guard : guards) {
        guard->update(deltaTime);
        checkCollisions(*guard);
    }

    // Update bombs (if any additional behavior is needed)
    for (auto& bomb : bombs) {
        bomb->update(deltaTime);
    }
}

void ObjectManager::render(sf::RenderWindow& window) {
    // Render the game board
    window.draw(gameBoard);

    // Render static objects
    for (const auto& obj : m_board) {
        if (obj) {
            obj->render(window);
        }
    }

    // Render player
    if (player) {
        player->render(window);
    }

    // Render guards
    for (const auto& guard : guards) {
        guard->render(window);
    }

    // Render bombs
    for (const auto& bomb : bombs) {
        bomb->render(window);
    }
}

void ObjectManager::checkCollisions(MovableObject& movable) {
    for (const auto& staticObj : m_board) {
        if (staticObj && movable.getBounds().intersects(staticObj->getBounds())) {
            // Handle collision based on the type of the static object
            movable.handleCollision(*staticObj);
        }
    }
}

void ObjectManager::handleWindowResize(const sf::Vector2u& newSize) {
    // Adjust the game board size and position to match the new window size
    gameBoard.setSize(sf::Vector2f(newSize.x * 0.75f, newSize.y * 0.75f)); // 75% of window size
    gameBoard.setPosition(newSize.x * 0.125f, newSize.y * 0.125f);         // Center the board
}

const std::vector<std::unique_ptr<Guard>>& ObjectManager::getGuards() const {
    return guards;
}

const std::vector<std::unique_ptr<Bomb>>& ObjectManager::getBombs() const {
    return bombs;
}

int ObjectManager::getLives() const {
    return lives;
}

int ObjectManager::getScore() const {
    return score;
}

void ObjectManager::addScore(int points) {
    score += points;
}

void ObjectManager::loseLife() {
    --lives;
}
