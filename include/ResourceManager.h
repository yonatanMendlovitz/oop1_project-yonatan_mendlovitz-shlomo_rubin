#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

class ResourceManager {
private:
	std::unordered_map<std::string, sf::Texture> textures;
	std::unordered_map<std::string, sf::SoundBuffer> sounds;
	std::unordered_map<std::string, sf::Font> fonts;
	sf::Music backgroundMusic;  // ✅ מוזיקה

	std::unordered_map<char, std::string> textureMapping;

	ResourceManager();

public:
	static ResourceManager& getInstance();

	const sf::Texture& getTexture(const std::string& filePath);
	const sf::SoundBuffer& getSound(const std::string& filePath);
	const sf::Font& getFont(const std::string& fontName);

	void playMusic(const std::string& filePath, bool loop = true);
	void stopMusic();
	void playSound(const std::string& filePath);
};
