#pragma once
//#include <SFML/Audio.hpp>
#include "ResourceManager.h"

class LevelTimer {
public:
    LevelTimer(float duration);
    void update(float deltaTime);
    void reset();
    bool isTimeUp() const;
    int getTimeLeft() const;

private:
    float timeLeft;
    float initialTime;

    
    sf::Sound tickSound;
    bool ticking = false;
};
