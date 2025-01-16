//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include "Player.h"
//
//namespace Textures {
//    sf::Texture playerTexture;
//
//    // Initialize and load the texture in a function
//    void loadTextures() {
//        if (!playerTexture.loadFromFile("wall.png")) {
//            // Handle error if the file fails to load
//            throw std::runtime_error("Failed to load texture: wall.png");
//        }
//    }
//};
//
//int main() {
//    // Call the function to load the texture
//    try {
//        Textures::loadTextures();
//    }
//    catch (const std::exception& e) {
//        // Handle the error, e.g., log it and exit
//        std::cerr << e.what() << std::endl;
//        return -1;
//    }
//
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Movable Object Example");
//    auto a = (sf::Sprite(Textures::playerTexture, sf::IntRect(sf::Vector2i(100, 100), sf::Vector2i(32, 32))));
//    // Create player
//    //Player player({ 100, 100 }, { 32, 32 }, Textures::playerTexture);
//    //player.setDirection({ 1, 0 }); // Moving right
//    //player.setVelocity(50); // Speed: 200 pixels per second
//
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
//
//        // Update player position
//        //player.update(0.01);
//       
//        // Render player
//        window.clear();
//        window.draw(a);
//        //player.render(window);
//        window.display();
//    }
//
//    return 0;
//}



#include <SFML/Graphics.hpp>
#include <iostream>

// מניח ש-Textures מוגדר כמו שצריך
//namespace Textures {
//    sf::Texture playerTexture;
//
//    void loadTextures() {
//        if (!playerTexture.loadFromFile("wall.png")) {
//            throw std::runtime_error("Failed to load texture: wall.png");
//        }
//    }
//}

int main() {
    sf::Texture playerTexture;
    std::cout<<playerTexture.loadFromFile("wall.png");
    //if (!playerTexture.loadFromFile("wall.png")) {
        //            throw std::runtime_error("Failed to load texture: wall.png");

    // יצירת חלון SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "דוגמה: הצגת ספרייט");
    // יצירת ספרייט a עם טקסטורה ותת-מלבן
    sf::Sprite a(playerTexture);
    std::cout<<playerTexture.getSize().x <<' '<< playerTexture.getSize().y<<"\n";
    //a.setScale(sf::Vector2f{ 0.1,0.1 });
    // הגדרת מיקום הספרייט למרכז החלון
    //a.setPosition(400.f, 300.f); // מיקום X=400, Y=300

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ציור הספרייט
        window.clear();
        window.draw(a); // מציירים את `a`
        window.display();
    }

    return 0;
}
