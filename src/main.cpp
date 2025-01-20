#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ObjectManager.h"
#include "Wall.h"
#include "Player.h"
#include "Guard.h"
#include "Bomb.h"

int main() {
    // יצירת חלון SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Level 1");
    Player player(sf::Vector2f(0,0), sf::Vector2f(100, 100));

    try {
        ObjectManager manager("level1.txt", 3, 0); 

        sf::Clock clock;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            float deltaTime = clock.restart().asSeconds();

            // עדכון האובייקטים
            manager.update(deltaTime);

            // רינדור האובייקטים
            window.clear();
            manager.render(window);
            window.display();
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
