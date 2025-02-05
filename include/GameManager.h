#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <memory>
#include <SFML/Graphics.hpp>

class LevelManager;
class Player;

class GameManager {
public:
    GameManager();
    void run();

private:
    sf::RenderWindow window;
    std::unique_ptr<Player> player;
};

#endif // GAME_MANAGER_H
