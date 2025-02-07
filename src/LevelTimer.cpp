#include "LevelTimer.h"


LevelTimer::LevelTimer(float duration) : timeLeft(duration), initialTime(duration) {
    tickSound.setBuffer(ResourceManager::getInstance().getSound("tick_tock.wav"));
    tickSound.setLoop(true);
}

void LevelTimer::update(float deltaTime) {
    if (timeLeft > 0) {
        timeLeft -= deltaTime;

        if (timeLeft <= 10.0f && !ticking) {
            tickSound.play();
            ticking = true;
        }

        if (timeLeft > 10.0f && ticking) {
            tickSound.stop();
            ticking = false;
        }
    }
}

void LevelTimer::reset() {
    timeLeft = initialTime;
    tickSound.stop(); // ✅ איפוס הצליל
    ticking = false;
}

bool LevelTimer::isTimeUp() const {
    return timeLeft <= 0;
}

int LevelTimer::getTimeLeft() const {
    return static_cast<int>(timeLeft);
}
