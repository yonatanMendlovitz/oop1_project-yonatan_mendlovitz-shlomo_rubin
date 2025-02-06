#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>

class LevelManager;
class Player;

class GameManager {
public:
    GameManager();
    void run();

private:
    sf::RenderWindow window;
    std::vector<std::string> levelFiles;
    std::unique_ptr<Player> player;

    void loadLevelFiles();
};

#endif // GAME_MANAGER_H
