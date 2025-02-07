#include "TransitionManager.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <thread>

void TransitionManager::fadeOut(sf::RenderWindow& window) {
    sf::RectangleShape overlay(sf::Vector2f(window.getSize()));
    overlay.setFillColor(sf::Color(0, 0, 0, 0));

    for (int alpha = 0; alpha <= 255; alpha += 5) {
        overlay.setFillColor(sf::Color(0, 0, 0, alpha));
        window.draw(overlay);
        window.display();
        sf::sleep(sf::milliseconds(15));
    }
}

void TransitionManager::fadeIn(sf::RenderWindow& window) {
    sf::RectangleShape overlay(sf::Vector2f(window.getSize()));
    overlay.setFillColor(sf::Color(0, 0, 0, 255));

    for (int alpha = 255; alpha >= 0; alpha -= 5) {
        overlay.setFillColor(sf::Color(0, 0, 0, alpha));
        window.draw(overlay);
        window.display();
        sf::sleep(sf::milliseconds(15));
    }
}

void TransitionManager::flashRed(sf::RenderWindow& window) {
    sf::RectangleShape overlay(sf::Vector2f(window.getSize()));
    overlay.setFillColor(sf::Color(255, 0, 0, 150));

    window.draw(overlay);
    window.display();
    sf::sleep(sf::milliseconds(200));
}

void TransitionManager::shakeScreen(sf::RenderWindow& window) {
    sf::Vector2i originalPos = window.getPosition();

    for (int i = 0; i < 10; i++) {
        window.setPosition(originalPos + sf::Vector2i(rand() % 10 - 5, rand() % 10 - 5));
        sf::sleep(sf::milliseconds(50));
    }
    window.setPosition(originalPos);
}
