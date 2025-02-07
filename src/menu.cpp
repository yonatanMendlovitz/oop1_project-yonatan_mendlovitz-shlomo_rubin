#include "Menu.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>

Menu::Menu(sf::RenderWindow& window) : m_window(window) {
    m_font = ResourceManager::getInstance().getFont("ARCADECLASSIC.TTF");
    std::vector<std::string> options = { "New Game", "Help", "Exit" };

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text(options[i], m_font, 40);
        text.setPosition(300, 200 + i * 60);
        text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
        m_options.push_back(text);
    }
}

void Menu::draw() {
    m_window.clear();
    for (const auto& option : m_options)
        m_window.draw(option);
    m_window.display();
}

void Menu::moveUp() {
    if (m_selectedIndex > 0) {
        m_options[m_selectedIndex].setFillColor(sf::Color::White);
        m_selectedIndex--;
        m_options[m_selectedIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (m_selectedIndex < m_options.size() - 1) {
        m_options[m_selectedIndex].setFillColor(sf::Color::White);
        m_selectedIndex++;
        m_options[m_selectedIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::run() {
    while (m_window.isOpen()) {
        draw();
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) moveUp();
                if (event.key.code == sf::Keyboard::Down) moveDown();
                if (event.key.code == sf::Keyboard::Enter) return m_selectedIndex;
            }
        }
    }
    return 2; // ברירת מחדל - יציאה
}
