#include "ObjectManager.h"
#include "Wall.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

ObjectManager::ObjectManager(const std::string& levelFilePath, int startingLives, int startingScore)
    : lives(startingLives), score(startingScore) {
    std::ifstream inputFile(levelFilePath);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open level file: " + levelFilePath);
    }

    // Initialize the board and objects
    initBoard(inputFile);
}

void ObjectManager::initBoard(std::ifstream& inputFile) {
    std::string line;
    int row = 0;

    while (std::getline(inputFile, line)) {
        m_board.push_back(std::vector<std::unique_ptr<StaticObject>>());
        for (int col = 0; col < line.size(); ++col) {
char tile = line[col];
            switch (tile) {
            case '#': // Wall
                m_board[row].push_back(std::make_unique<Wall>(sf::Vector2f(col * 100, row * 100), sf::Vector2f(100, 100)));//eljfhjkergruegtuoreu
                break;
            case '/': // Player
                m_board[row].push_back(nullptr); // No static object
                player = std::make_unique<Player>(sf::Vector2f(col * 100, row * 100), sf::Vector2f(100, 100));
                break;
            case '!': // Enemy (Guard)
                m_board[row].push_back(nullptr); // No static object
                guards.push_back(std::make_unique<Guard>(sf::Vector2f(col * 100, row * 100), sf::Vector2f(100, 100)));
                break;            
            case ' ': // Empty space
            default:
                m_board[row].push_back(nullptr);
                break;
            }
        }
        ++row;
    }
}

void ObjectManager::addBomb(sf::Vector2f position, float timer, float radius) {
    bombs.push_back(std::make_unique<Bomb>(position, sf::Vector2f(100, 100)));
}

void ObjectManager::update(float deltaTime) {
    // Update the player
    if (player) {
        player->update(deltaTime);
    }

    // Update guards
    for (auto& guard : guards) {
        guard->update(deltaTime);
    }

    // Update bombs
    for (auto& bomb : bombs) {
        bomb->update(deltaTime);
    }
}

void ObjectManager::render(sf::RenderWindow& window) {
    // Render static objects
    for (const auto& row : m_board) {
        for (const auto& obj : row) {
            if (obj) {
                obj->render(window);
            }
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

Player* ObjectManager::getPlayer() const {
    return player.get();
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

