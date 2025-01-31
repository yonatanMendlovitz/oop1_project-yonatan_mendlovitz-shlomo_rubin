#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "LevelManager.h"
#include "Player.h"

class GameManager {
public:
    GameManager();
    void run();

private:
    sf::RenderWindow window;
    std::unique_ptr<Player> player;
};

