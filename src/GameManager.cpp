//#include <string>
//#include <fstream>
//#include <iostream>
#include "GameManager.h"
#include "LevelManager.h"


GameManager::GameManager()
    : window(sf::VideoMode(800, 600), "Bomberman") {
    player = std::make_unique<Player>(sf::Vector2f(0, 0), sf::Vector2f(0, 0));
}

void GameManager::run() {
    while (window.isOpen() && player->getLives()) {
        LevelManager level("level1.txt", std::move(player), window);
        player = level.run();  
    }
    std::cout << "Game Over!" << std::endl;
}
