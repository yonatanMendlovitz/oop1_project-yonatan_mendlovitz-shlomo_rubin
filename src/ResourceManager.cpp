#include "ResourceManager.h"
#include <stdexcept>
#include <iostream>

ResourceManager::ResourceManager() {
    textureMapping = {
        {'#', "wall.png"},
        {'/', "player.png"},
        {'!', "guard.png"},
        {'@', "stone.png"},
        {'D', "door.png"},
        {' ', "blank.png"}
    };
}

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager instance;
    return instance;
}

const sf::Texture& ResourceManager::getTexture(const std::string& filePath) {
    if (textures.find(filePath) == textures.end()) {
        sf::Texture texture;
        if (!texture.loadFromFile(filePath)) {
            throw std::runtime_error("Failed to load texture: " + filePath);
        }
        textures[filePath] = std::move(texture);
    }
    return textures[filePath];
}

const sf::SoundBuffer& ResourceManager::getSound(const std::string& filePath) {
    if (sounds.find(filePath) == sounds.end()) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(filePath)) {
            throw std::runtime_error("Failed to load sound: " + filePath);
        }
        sounds[filePath] = std::move(buffer);
    }
    return sounds[filePath];
}

const sf::Font& ResourceManager::getFont(const std::string& fontName) {
    if (fonts.find(fontName) == fonts.end()) {
        sf::Font font;
        if (!font.loadFromFile(fontName)) {
            throw std::runtime_error("Failed to load font: " + fontName);
        }
        fonts[fontName] = std::move(font);
    }
    return fonts[fontName];
}

// ✅ השמעת מוזיקת רקע
void ResourceManager::playMusic(const std::string& filePath, bool loop) {
    if (!backgroundMusic.openFromFile(filePath)) {
        throw std::runtime_error("Failed to load music: " + filePath);
    }
    backgroundMusic.setLoop(loop);
    backgroundMusic.play();
}

void ResourceManager::stopMusic() {
    backgroundMusic.stop();
}

// ✅ השמעת אפקטים קוליים
void ResourceManager::playSound(const std::string& filePath) {
    static sf::Sound soundEffect;
    soundEffect.setBuffer(getSound(filePath));
    soundEffect.play();
}
