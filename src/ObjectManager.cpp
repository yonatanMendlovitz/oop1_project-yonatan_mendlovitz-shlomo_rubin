#include "ObjectManager.h"
#include "Wall.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
//#include <iostream>

ObjectManager::ObjectManager(const std::string& levelFilePath, int startingLives, int startingScore, Player* player)
    : lives(startingLives), score(startingScore), player(player) {
    std::ifstream inputFile(levelFilePath);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open level file: " + levelFilePath);
    }
    initBoard(inputFile);

    gameBoard.setTexture(&ResourceManager::getInstance().getTexture("gameImage.jpeg"));
    gameBoard.setSize(sf::Vector2f(600, 400)); // Initial size
    gameBoard.setPosition(100.0f, 100.0f);          // Centered in the window
}

void ObjectManager::initBoard(std::ifstream& inputFile) {
    std::string line;
    float row = 0;

    while (std::getline(inputFile, line)) {
        for (float col = 0; col < line.size(); ++col) {
            char tile = line[col];
            switch (tile) {
            case '#': // Wall
                m_board.push_back(std::make_unique<Wall>(sf::Vector2f(col * 100.0f, row * 100.0f), sf::Vector2f(100.0f, 100.0f)));
                break;
            case '@':
                m_board.push_back(std::make_unique<Stone>(sf::Vector2f(col * 100.0f, row * 100.0f), sf::Vector2f(100.0f, 100.0f)));
                break;

            case '/': // Player
                player->setPosition(sf::Vector2f(col * 100.0f, row * 100.0f));
                player->setSize(sf::Vector2f(100.0f, 100.0f));
                player->setDirection(sf::Vector2f(1, 0));
                player->setVelocity(180);
                break;

            case '!': // Enemy (Guard)
                guards.push_back(std::make_unique<Guard>(sf::Vector2f(col * 100.0f, row * 100.0f), sf::Vector2f(100.0f, 100.0f)));
                guards.back()->setDirection(sf::Vector2f(1, 1));
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
    if (player) {
        player->update(deltaTime);
        checkCollisions(*player);
    }
    for (auto& guard : guards) {
        guard->update(deltaTime );
        checkCollisions(*guard);
    }
    for (auto& bomb : bombs) {
        bomb->update(deltaTime);//xyz
    }
}

//void ObjectManager::render(sf::RenderWindow& window) {
//    window.draw(gameBoard);
//    for (const auto& obj : m_board) {
//        if (obj) {
//            obj->render(window);
//        }
//    }
//
//    if (player) {
//        player->render(window);
//    }
//    for (const auto& guard : guards) {
//        guard->render(window);
//    }
//    for (const auto& bomb : bombs) {
//        bomb->render(window);
//    }
//}

void ObjectManager::checkCollisions(MovableObject& movable) {
    for (const auto& staticObj : m_board) {
        if (staticObj && movable.getBounds().intersects(staticObj->getBounds())) {
            movable.handleCollision(*staticObj);
        }
    }
}

void ObjectManager::handleWindowResize(const sf::Vector2u& newSize) {
    gameBoard.setSize(sf::Vector2f(newSize.x * 0.75f, newSize.y * 0.75f)); // 75% of window size
    gameBoard.setPosition(newSize.x * 0.125f, newSize.y * 0.125f);         // Center the board
    //gameBoard.setSize(sf::Vector2f(newSize.x , newSize.y )); // 75% of window size
    //gameBoard.setPosition(0,0);         // Center the board
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
