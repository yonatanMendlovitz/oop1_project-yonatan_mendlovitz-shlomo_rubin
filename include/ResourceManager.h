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

    // Map of character keys to file paths for textures
    std::unordered_map<char, std::string> textureMapping;

    ResourceManager() {
        // Initialize texture mapping
        textureMapping = {
            {'#', "wall.png"},       // Wall texture
            {'/', "player.png"},     // Player texture
            {'!', "guard.png"},      // Guard texture
            {'@', "stone.png"},      // Stone texture
            {'D', "door.png"},       // Door texture
            //{'!', "explosion.png"},  // Explosion texture//xyz
            {' ', "blank.png"}       // Default empty texture
        };
    }

public:
    // Singleton instance access
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    // Get texture by file path
    const sf::Texture& getTexture(const std::string& filePath) {
        if (textures.find(filePath) == textures.end()) {
            sf::Texture texture;
            if (!texture.loadFromFile(filePath)) {
                throw std::runtime_error("Failed to load texture: " + filePath);
            }
            textures[filePath] = std::move(texture);
        }
        return textures[filePath];
    }

    // Get sound by file path
    const sf::SoundBuffer& getSound(const std::string& filePath) {
        if (sounds.find(filePath) == sounds.end()) {
            sf::SoundBuffer sound;
            if (!sound.loadFromFile(filePath)) {
                throw std::runtime_error("Failed to load sound: " + filePath);
            }
            sounds[filePath] = std::move(sound);
        }
        return sounds[filePath];
    }

    // Get texture by character key
    const sf::Texture& getTexture(char key) {
        if (textureMapping.find(key) == textureMapping.end()) {
            throw std::runtime_error(std::string("No texture mapped for key: ") + key);
        }
        return getTexture(textureMapping[key]);
    }
};
