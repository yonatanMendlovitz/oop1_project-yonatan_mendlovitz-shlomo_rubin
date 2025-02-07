#pragma once
#include <SFML/Graphics.hpp>

class TransitionManager {
public:
    static void fadeOut(sf::RenderWindow& window);
    static void fadeIn(sf::RenderWindow& window);
    static void flashRed(sf::RenderWindow& window);
    static void shakeScreen(sf::RenderWindow& window);
};

