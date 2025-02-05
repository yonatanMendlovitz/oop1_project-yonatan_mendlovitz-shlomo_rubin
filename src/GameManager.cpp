#include "GameManager.h"
#include "LevelManager.h"
#include <iostream>
#include <fstream>
#include <vector>

GameManager::GameManager()
    : window(sf::VideoMode(800, 600), "Bomberman") {
    sf::Vector2f playerSize(50.0f, 50.0f);
    player = std::make_unique<Player>(sf::Vector2f(0, 0), playerSize);
}

void GameManager::run() {
    std::cout << "Game started!" << std::endl;

    std::vector<std::string> levelFiles;
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
    file.close();

    if (levelFiles.empty()) {
        std::cerr << "Error: No levels found in fileList.txt!" << std::endl;
        return;
    }

    // ריצה על השלבים לפי הסדר
    for (const auto& levelFile : levelFiles) {
        if (!window.isOpen() || !player || player->getLives() <= 0)
            break;

        std::cout << "Loading level: " << levelFile << std::endl;
        LevelManager level(levelFile, std::move(player), window);
        player = level.run();

        if (!player) {
            std::cout << "Player lost all lives!" << std::endl;
            break;
        }
    }

    std::cout << "Game Over!" << std::endl;
}
