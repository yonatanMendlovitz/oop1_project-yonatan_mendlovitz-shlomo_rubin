#pragma once
#include <vector>
#include <memory>
#include "MovableObject.h"
#include "StaticObject.h"
#include "Player.h"
#include "Guard.h"

class CollisionHandler {
public:
    static void checkCollisions(std::vector<std::unique_ptr<MovableObject>>& movables,
        std::vector<std::unique_ptr<StaticObject>>& statics);
    static void checkMovableCollisions(std::vector<std::unique_ptr<MovableObject>>& movables);
};
