#include "GameManager.h"
#include "LevelManager.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include "HelpScreen.h"


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
    Menu menu(window);
    int choice = menu.run();

    if (choice == 2) return; // Exit
    if (choice == 1) { // Help
        HelpScreen help(window);
        help.run();
        run(); // חזרה לתפריט אחרי העזרה
    }

    for (const auto& levelFile : levelFiles) {
        if (!window.isOpen() || !player || player->getLives() <= 0)
            break;

        ResourceManager::getInstance().playMusic("03_level_theme.wav");
        LevelManager level(levelFile, std::move(player), window);
        player = level.run();
        ResourceManager::getInstance().stopMusic();

        if (!player) {
            std::cout << "Player lost all lives!" << std::endl;
            break;
        }
    }
    run();
}
