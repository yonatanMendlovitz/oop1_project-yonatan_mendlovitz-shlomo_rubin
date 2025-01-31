#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
    : window(sf::VideoMode(800, 600), "My Game") {
    player = std::make_unique<Player>(sf::Vector2f(100, 100), sf::Vector2f(50, 50));
}

void GameManager::run() {
    while (window.isOpen() && player->anIAlive()) {
        LevelManager level("level1.txt", std::move(player), window);
        player = level.run();  // החזרת השחקן בסיום השלב
    }

    std::cout << "Game Over!" << std::endl;
}

