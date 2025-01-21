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
    Player* player; // Raw pointer to the player (not owning)
    std::vector<std::unique_ptr<StaticObject>> m_board;
    std::vector<std::unique_ptr<Guard>> guards;
    std::vector<std::unique_ptr<Bomb>> bombs;

    int lives;
    int score;

    void initBoard(std::ifstream& inputFile);
    void checkCollisions(MovableObject& movable);
public:
    ObjectManager(const std::string& levelFilePath, int startingLives, int startingScore, Player* player);

    void addBomb(sf::Vector2f position, float timer, float radius);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    //Player* getPlayer() const;
    const std::vector<std::unique_ptr<Guard>>& getGuards() const;
    const std::vector<std::unique_ptr<Bomb>>& getBombs() const;

    int getLives() const;
    int getScore() const;
    void addScore(int points);
    void loseLife();
};
