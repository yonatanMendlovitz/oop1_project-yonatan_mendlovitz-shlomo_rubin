#include "GameManager.h"
#include "LevelManager.h"
#include <iostream>
#include <fstream>

GameManager::GameManager()
    : window(sf::VideoMode(800, 600), "Bomberman") {
    player = std::make_unique<Player>(sf::Vector2f(0, 0), sf::Vector2f(50, 50));
    loadLevelFiles();
}

void GameManager::loadLevelFiles() {
    std::ifstream file("fileList.txt");
    if (!file) {
        std::cerr << "Error: Could not open fileList.txt!" << std::endl;
        return;
    }

    std::string levelName;
    while (std::getline(file, levelName)) {
        if (!levelName.empty()) {
            levelFiles.push_back(levelName);
        }
    }

    if (levelFiles.empty()) {
        std::cerr << "Error: No levels found in fileList.txt!" << std::endl;
    }
}

void GameManager::run() {
    std::cout << "Game started!" << std::endl;
    
    for (const auto& levelFile : levelFiles) {
        if (!window.isOpen() || !player || player->getLives() <= 0)
            break;
        ResourceManager::getInstance().playMusic("03_level_theme.wav");
        std::cout << "Loading level: " << levelFile << std::endl;
        LevelManager level(levelFile, std::move(player), window);
        player = level.run();
        ResourceManager::getInstance().stopMusic();
        if (!player) {
            std::cout << "Player lost all lives!" << std::endl;
            break;
        }
    }
    
    std::cout << "Game Over!" << std::endl;
}
