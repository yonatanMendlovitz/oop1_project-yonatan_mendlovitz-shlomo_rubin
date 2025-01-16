#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <chrono>
#include <thread>
using namespace std::chrono_literals;


int main()
{
    

    sf::RenderWindow window(sf::VideoMode(800, 600), "Movable Object Example");
    sf::Sound sound = sf::Sound();//);
    sound.setBuffer(*ResourceManager::Sounds.getSound('1'));
    sound.setLoop(true);
  
    Player player(sf::Vector2f{ 0, 0 }, sf::Vector2f{100,100 }, ResourceManager::Textures.getTexture('/'));
    player.setDirection({ 1, 1 });
    player.setVelocity(100); 
    sf::Clock clock;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        if(player.getPosition().y+ player.getSize().y >window.getSize().y || player.getPosition().y < 0 )
            player.setDirection({ player.getDirection().x, -1 * player.getDirection().y });
        if(player.getPosition().x+ player.getSize().x >window.getSize().x || player.getPosition().x < 0)
            player.setDirection({ -1 * player.getDirection().x, player.getDirection().y });
       player.update(deltaTime);
        window.clear();
        player.render(window);
        window.display();
    }
    return 0;
}
