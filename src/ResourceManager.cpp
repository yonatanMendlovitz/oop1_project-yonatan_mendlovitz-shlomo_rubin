#include "ResourceManager.h"

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
        sf::SoundBuffer sound;
        if (!sound.loadFromFile(filePath)) {
            throw std::runtime_error("Failed to load sound: " + filePath);
        }
        sounds[filePath] = std::move(sound);
    }
    return sounds[filePath];
}

const sf::Font& ResourceManager::getFont(const std::string& filePath) {
    if (fonts.find(filePath) == fonts.end()) {
        loadFont(filePath);
    }
    return fonts[filePath];
}

void ResourceManager::loadFont(const std::string& filePath) {
    sf::Font font;
    if (!font.loadFromFile(filePath)) {
        throw std::runtime_error("Failed to load font: " + filePath);
    }
    fonts[filePath] = std::move(font);
}
