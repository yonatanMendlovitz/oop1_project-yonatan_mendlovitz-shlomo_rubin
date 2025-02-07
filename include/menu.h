#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
public:
    Menu(sf::RenderWindow& window);
    int run(); // מחזיר את הבחירה של המשתמש

private:
    sf::RenderWindow& m_window;
    sf::Font m_font;
    std::vector<sf::Text> m_options;
    int m_selectedIndex = 0;

    void draw();
    void moveUp();
    void moveDown();
};
