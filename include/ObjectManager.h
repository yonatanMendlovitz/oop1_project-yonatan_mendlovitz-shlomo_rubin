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
    std::vector<std::unique_ptr<StaticObject>> m_board;
    std::vector<std::unique_ptr<Guard>> guards;        
    std::vector<std::unique_ptr<Bomb>> bombs;          
    Player* player;                                    
    sf::RectangleShape gameBoard;                      

    int lives;
    int score;

    void initBoard(std::ifstream& inputFile);
    void checkCollisions(MovableObject& movable);       // Check collisions for a movable object

public:
    ObjectManager(const std::string& levelFilePath, int startingLives, int startingScore, Player* player);
    void addBomb(sf::Vector2f position, float timer, float radius);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    void handleWindowResize(const sf::Vector2u& newSize);
    const std::vector<std::unique_ptr<Guard>>& getGuards() const;
    const std::vector<std::unique_ptr<Bomb>>& getBombs() const;
    int getLives() const;
    int getScore() const;
    void addScore(int points);
    void loseLife();
};

#endif // OBJECT_MANAGER_H
