#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML/System/Vector2.hpp>
#include <string>

// General Game Constants
constexpr float BASE_SPEED = 100.0f;
constexpr float ACCELERATION = 1.0f;

// Directions (for movement)
static const sf::Vector2f UP(0, -1);
static const sf::Vector2f DOWN(0, 1);
static const sf::Vector2f LEFT(-1, 0);
static const sf::Vector2f RIGHT(1, 0);

// Tile Symbols
constexpr char WALL_SYMBOL = '#';
constexpr char PLAYER_SYMBOL = '/';
constexpr char GUARD_SYMBOL = '!';
constexpr char STONE_SYMBOL = '@';
constexpr char DOOR_SYMBOL = 'D';
constexpr char EMPTY_SYMBOL = ' ';

// File Paths for Textures
static const std::string WALL_TEXTURE = "wall.png";
static const std::string PLAYER_TEXTURE = "player.png";
static const std::string ENEMY_TEXTURE = "guard.png";
static const std::string STONE_TEXTURE = "stone.png";
static const std::string DOOR_TEXTURE = "door.png";
static const std::string EMPTY_TEXTURE = "blank.png";
//void donothing() {};
#endif // CONSTANTS_H
