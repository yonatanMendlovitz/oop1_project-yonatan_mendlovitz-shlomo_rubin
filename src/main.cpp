//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include "Player.h"
//#include <chrono>
//#include <thread>
//using namespace std::chrono_literals;
//
//
//int main()
//{
//    
//
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Movable Object Example");
//    sf::Sound sound = sf::Sound();//);
//    sound.setBuffer(ResourceManager::getInstance().getSound("01_main_menu.wav"));
//    sound.setLoop(true);
//  
//    Player player(sf::Vector2f{ 0, 0 }, sf::Vector2f{100,100 }, ResourceManager::getInstance().getTexture("player.png"));
//    player.setDirection({ 1, 1 });
//    player.setVelocity(100); 
//    sf::Clock clock;
//    
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        float deltaTime = clock.restart().asSeconds();
//        if(player.getPosition().y+ player.getSize().y >window.getSize().y || player.getPosition().y < 0 )
//            player.setDirection({ player.getDirection().x, -1 * player.getDirection().y });
//        if(player.getPosition().x+ player.getSize().x >window.getSize().x || player.getPosition().x < 0)
//            player.setDirection({ -1 * player.getDirection().x, player.getDirection().y });
//       player.update(deltaTime);
//        window.clear();
//        window.draw(sf::Sprite(ResourceManager::getInstance().getTexture("gameImage.jpeg")));
//        player.render(window);
//        window.display();
//    }
//    return 0;
//}



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

    try {
        // יצירת ObjectManager לטעינת הקובץ וניהול האובייקטים
        ObjectManager manager("level1.txt", 3, 0); // חיים התחלתיים: 3, ניקוד: 0

        // לולאת המשחק
        sf::Clock clock;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            // חישוב זמן לפריים
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
