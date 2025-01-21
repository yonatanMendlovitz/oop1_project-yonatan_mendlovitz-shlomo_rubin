#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "MovableObject.h"
#include "Player.h"
#include "Guard.h"
#include "Bomb.h"

class ObjectManager {
private:
    std::vector<std::unique_ptr<StaticObject>> m_board; // Static objects
    std::vector<std::unique_ptr<Guard>> guards;         // Enemies
    std::vector<std::unique_ptr<Bomb>> bombs;           // Bombs
    Player* player;                                     // Single player

    sf::RectangleShape gameBoard;                       // Game board rectangle

    int lives;
    int score;

    void initBoard(std::ifstream& inputFile);
    void checkCollisions(MovableObject& movable);       // Check collisions for a movable object

public:
    // Constructor
    ObjectManager(const std::string& levelFilePath, int startingLives, int startingScore, Player* player);

    // Add bombs
    void addBomb(sf::Vector2f position, float timer, float radius);

    // Update game objects
    void update(float deltaTime);

    // Render game objects
    void render(sf::RenderWindow& window);

    // Handle window resize
    void handleWindowResize(const sf::Vector2u& newSize);

    // Getters
    const std::vector<std::unique_ptr<Guard>>& getGuards() const;
    const std::vector<std::unique_ptr<Bomb>>& getBombs() const;
    int getLives() const;
    int getScore() const;

    // Scoring and lives management
    void addScore(int points);
    void loseLife();
};

#endif // OBJECT_MANAGER_H
