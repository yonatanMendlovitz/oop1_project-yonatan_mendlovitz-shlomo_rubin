#pragma once
#include <SFML/Graphics.hpp>

class GameHUD {
public:
    GameHUD(sf::RenderWindow& gameWindow, int levelNumber);
    void update(int lives, int score, int timeLeft); // ⬅️ וודא שזה קיים
    void render(); // ⬅️ וודא שזה קיים

private:
    sf::RenderWindow& gameWindow;
    sf::Font font;
    sf::Text levelText, scoreText, timerText;
};
