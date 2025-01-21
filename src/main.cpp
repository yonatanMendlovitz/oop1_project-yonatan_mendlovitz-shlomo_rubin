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
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Level 1");

	Player player(sf::Vector2f(0, 0), sf::Vector2f(100, 100));

	try {
		// יצירת מנהל האובייקטים
		ObjectManager manager("level1.txt", 3, 0, &player);

		// שעון SFML למדידת זמן בין פריימים
		sf::Clock clock;

		while (window.isOpen()) {
			// טיפול באירועים
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if (event.type == sf::Event::KeyPressed) {
					switch (event.key.code) {
					case sf::Keyboard::Escape:
						window.close();
						break;
					case sf::Keyboard::Up:
						player.setDirection(sf::Vector2f(0,-1));
						break;
					case sf::Keyboard::Down:
						player.setDirection(sf::Vector2f(0, 1));
						break;
					case sf::Keyboard::Left:
						player.setDirection(sf::Vector2f(-1, 0));
						break;
					case sf::Keyboard::Right:
						player.setDirection(sf::Vector2f(1, 0));
						break;
					default:
						break;
					}
				}
			}

				float deltaTime = clock.restart().asSeconds();
				manager.update(deltaTime);

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
