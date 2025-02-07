#include "GameHUD.h"
#include <iostream>

GameHUD::GameHUD(sf::RenderWindow& gameWindow, int levelNumber) : gameWindow(gameWindow) {
    if (!font.loadFromFile("ARCADECLASSIC.TTF")) {
        throw std::runtime_error("Failed to load font.");
    }

    levelText.setFont(font);
    levelText.setCharacterSize(20);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(10, 20);

    scoreText = levelText;
    scoreText.setPosition(10, 60);

    timerText = levelText;
    timerText.setPosition(10, 100);
}

void GameHUD::update(int lives, int score, int timeLeft) { // ✅ מימוש חסר
    levelText.setString("Level: " + std::to_string(lives));
    scoreText.setString("Score: " + std::to_string(score));
    timerText.setString("Time Left: " + std::to_string(timeLeft));
}

void GameHUD::render() { // ✅ מימוש חסר
    gameWindow.draw(levelText);
    gameWindow.draw(scoreText);
    gameWindow.draw(timerText);
}
