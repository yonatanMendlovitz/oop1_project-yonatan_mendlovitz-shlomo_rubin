#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class HelpScreen {
public:
    HelpScreen(sf::RenderWindow& window);
    void run(); // מפעיל את מסך העזרה

private:
    sf::RenderWindow& m_window;
    sf::Font m_font;
    std::vector<sf::Text> m_instructions;
    int m_currentPage = 0;

    void draw();
    void nextPage();
    void prevPage();
};
