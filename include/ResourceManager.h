#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



namespace ResourceManager {

//===========================================
//=============visual files===================
//===========================================
    class TextureManager {
    public:
        TextureManager() {
            if (!p_blank.loadFromFile("blank.png"))
                std::cerr << "Error loading blank.png\n";
            if (!p_guard.loadFromFile("guard.png"))
                std::cerr << "Error loading guard.png\n";
            if (!p_player.loadFromFile("player.png"))
                std::cerr << "Error loading player.png\n";
            if (!p_stone.loadFromFile("stone.png"))
                std::cerr << "Error loading stone.png\n";
            if (!p_wall.loadFromFile("wall.png"))
                std::cerr << "Error loading wall.png\n";
            if (!p_door.loadFromFile("door.png"))
                std::cerr << "Error loading door.png\n";
            if (!p_game.loadFromFile("gameImage.jpeg"))
                std::cerr << "Error loading gameImage.jpeg\n";
        }

        const sf::Texture* getTexture(char signPhoto) const {
            switch (signPhoto) {
            case '!': return &p_guard;  // Guard texture
            case '/': return &p_player; // Player texture
            case '@': return &p_stone;  // Stone texture
            case '#': return &p_wall;   // Wall texture
            case 'D': return &p_door;   // Door texture
            //case '$': return &p_gift;   // Game image texture
            case 'g': return &p_game;   // Game image texture
            default:   return &p_blank; // Default blank texture
            }
        }

    private:
        sf::Texture p_blank;
        sf::Texture p_guard;
        sf::Texture p_player;
        sf::Texture p_stone;
        sf::Texture p_wall;
        sf::Texture p_door;
        sf::Texture p_game;
    };
//===========================================
//=============sound files===================
//===========================================
    class SoundManager {
    public:
        SoundManager() {
            if (!p_mainMenu.loadFromFile("01_main_menu.wav"))
                std::cerr << "Error loading 01_main_menu.wav\n";
            if (!p_levelBegins.loadFromFile("02_the_level_begins.wav"))
                std::cerr << "Error loading 02_the_level_begins.wav\n";
            if (!p_levelTheme.loadFromFile("03_level_theme.wav"))
                std::cerr << "Error loading 03_level_theme.wav\n";
            if (!p_doorSearch.loadFromFile("04_door_search.wav"))
                std::cerr << "Error loading 04_door_search.wav\n";
            if (!p_levelCompleted.loadFromFile("05_level_completed.wav"))
                std::cerr << "Error loading 05_level_completed.wav\n";
            if (!p_invincibilityTheme.loadFromFile("06_invincibility_theme.wav"))
                std::cerr << "Error loading 06_invincibility_theme.wav\n";
            if (!p_death.loadFromFile("08_death.wav"))
                std::cerr << "Error loading 08_death.wav\n";
            if (!p_gameOver.loadFromFile("09_game_over.wav"))
                std::cerr << "Error loading 09_game_over.wav\n";
            if (!p_endingTheme.loadFromFile("10_ending_theme.wav"))
                std::cerr << "Error loading 10_ending_theme.wav\n";
        }

        const sf::SoundBuffer* getSound(char soundIdentifier) const {
            switch (soundIdentifier) {
            case '1': return &p_mainMenu;         // Main menu sound
            case '2': return &p_levelBegins;      // Level begins sound
            case '3': return &p_levelTheme;       // Level theme sound
            case '4': return &p_doorSearch;       // Door search sound
            case '5': return &p_levelCompleted;   // Level completed sound
            case '6': return &p_invincibilityTheme; // Invincibility theme sound
            case '8': return &p_death;            // Death sound
            case '9': return &p_gameOver;         // Game over sound
            case 'A': return &p_endingTheme;      // Ending theme sound
            default: return nullptr;              // Invalid identifier
            }
        }

    private:
        sf::SoundBuffer p_mainMenu;
        sf::SoundBuffer p_levelBegins;
        sf::SoundBuffer p_levelTheme;
        sf::SoundBuffer p_doorSearch;
        sf::SoundBuffer p_levelCompleted;
        sf::SoundBuffer p_invincibilityTheme;
        sf::SoundBuffer p_death;
        sf::SoundBuffer p_gameOver;
        sf::SoundBuffer p_endingTheme;
    };

    const auto Sounds = SoundManager();
    const auto Textures = TextureManager();

};
