#include "HelpScreen.h"
#include "ResourceManager.h"
#include <SFML/Window/Event.hpp>

HelpScreen::HelpScreen(sf::RenderWindow& window) : m_window(window) {
    m_font = ResourceManager::getInstance().getFont("VPPixel-Simplified.otf");
    std::vector<std::string> pages = {
        "Welcome  to  Bomberman!\n\nUse arrow keys to move.\nPress B to drop bombs.",
        "Avoid guards!\n\nBombs explode after a few seconds.",
        "Reach the door to win!",
        "Good luck! Press ESC to return."
    };

    for (size_t i = 0; i < pages.size(); ++i) {
        sf::Text text(pages[i], m_font, 30);
        text.setPosition(100, 150);
        text.setFillColor(sf::Color::White);
        m_instructions.push_back(text);
    }
}

void HelpScreen::draw() {
    m_window.clear(sf::Color(0, 0, 50)); // רקע כחול כהה
    m_window.draw(m_instructions[m_currentPage]);

    sf::Text next("Use Left/Right to navigate | ESC to exit", m_font, 20);
    next.setPosition(100, 500);
    next.setFillColor(sf::Color::Yellow);
    m_window.draw(next);

    m_window.display();
}

void HelpScreen::nextPage() {
    if (m_currentPage < m_instructions.size() - 1)
        m_currentPage++;
}

void HelpScreen::prevPage() {
    if (m_currentPage > 0)
        m_currentPage--;
}

void HelpScreen::run() {
    while (m_window.isOpen()) {
        draw();
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) nextPage();
                if (event.key.code == sf::Keyboard::Left) prevPage();
                if (event.key.code == sf::Keyboard::Escape) return;
            }
        }
    }
}
