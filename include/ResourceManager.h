#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <iostream>
#include "Constants.h"

class ResourceManager {
private:
    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, sf::SoundBuffer> sounds;
    std::unordered_map<std::string, sf::Font> fonts;
    std::unordered_map<char, std::string> textureMapping;

    ResourceManager() {
        textureMapping = {
            {'#', "wall.png"},
            {'/', "player.png"},
            {'!', "guard.png"},
            {'@', "stone.png"},
            {'D', "door.png"},
            {' ', "blank.png"}
        };
        //loadFont("default", "resources/fonts/arial.ttf");
    }

public:
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    const sf::Texture& getTexture(const std::string& filePath);
    const sf::SoundBuffer& getSound(const std::string& filePath);
    const sf::Font& getFont(const std::string& fontName);

private:
    void loadFont( const std::string& filePath);
};
