#pragma once
#include <vector>
#include <memory>
#include <string>
#include "StaticObject.h"
#include "MovableObject.h"
#include "Player.h"
#include "Guard.h"
#include "Bomb.h"

class ObjectManager {
private:
    std::vector<std::vector<std::unique_ptr<StaticObject>>> m_board; // Static objects
    std::vector<std::unique_ptr<Guard>> guards;                      // Enemies
    std::vector<std::unique_ptr<Bomb>> bombs;                        // Bombs
    std::unique_ptr<Player> player;                                  // Single player

    int lives;
    int score;

    void initBoard(std::ifstream& inputFile);

public:
    ObjectManager(const std::string& levelFilePath, int startingLives, int startingScore);

    void addBomb(sf::Vector2f position, float timer, float radius);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    Player* getPlayer() const;
    const std::vector<std::unique_ptr<Guard>>& getGuards() const;
    const std::vector<std::unique_ptr<Bomb>>& getBombs() const;

    int getLives() const;
    int getScore() const;
    void addScore(int points);
    void loseLife();
};
