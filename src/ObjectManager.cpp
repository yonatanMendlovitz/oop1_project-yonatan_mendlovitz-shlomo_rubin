#include "ObjectManager.h"
#include "CollisionHandler.h"
#include <iostream>

ObjectManager::ObjectManager(sf::RenderWindow& window)
    : m_window(window) {
}

void ObjectManager::loadObjects(const std::vector<std::string>& levelData, const sf::Vector2f& objectSize, const sf::Vector2f& boardOffset) {
    m_boardOffset = boardOffset;
    staticObjects.clear();
    movableObjects.clear();
    bombs.clear();

    for (int row = 0; row < levelData.size(); row++) {
        for (int col = 0; col < levelData[row].size(); ++col) {
            sf::Vector2f position(col * objectSize.x, row * objectSize.y);
            position += m_boardOffset;

            switch (levelData[row][col]) {
            case '#':
                staticObjects.push_back(std::make_unique<Wall>(position, objectSize));
                break;
            case '!':
                movableObjects.push_back(std::make_unique<Guard>(position, objectSize));
                break;
            case '@':
                staticObjects.push_back(std::make_unique<Stone>(position, objectSize));
                break;
            case 'D':
                staticObjects.push_back(std::make_unique<Door>(position, objectSize));
                break;
            case '/':
                if (!movableObjects.empty()) {
                    movableObjects.at(0)->setPosition(position);
                    movableObjects.at(0)->setSize(objectSize);
                }
                break;
            }
        }
    }
}

void ObjectManager::update(float deltaTime) {
    bombs.erase(std::remove_if(bombs.begin(), bombs.end(), [](const std::unique_ptr<Bomb>& bomb) { return !bomb->isAlive(); }), bombs.end());
    movableObjects.erase(std::remove_if(movableObjects.begin(), movableObjects.end(), [](const std::unique_ptr<MovableObject>& movable) { return !movable->isAlive(); }), movableObjects.end());
    staticObjects.erase(std::remove_if(staticObjects.begin(), staticObjects.end(), [](const std::unique_ptr<StaticObject>& obj) { return !obj->isAlive(); }), staticObjects.end());

    for (auto& movable : movableObjects)
        movable->update(deltaTime);

    for (auto& bomb : bombs) {
        bomb->update(deltaTime);
        if (bomb->isExploded())
            bomb->explode(staticObjects, movableObjects);
    }

    CollisionHandler::checkCollisions(movableObjects, staticObjects);
    CollisionHandler::checkMovableCollisions(movableObjects);
}

void ObjectManager::render() const {
    for (const auto& obj : staticObjects)
        obj->render(m_window);
    for (const auto& movable : movableObjects)
        movable->render(m_window);
    for (const auto& bomb : bombs)
        bomb->render(m_window);
}

void ObjectManager::updateSizes(const sf::Vector2f& newSize, const sf::Vector2f& boardOffset) {
    m_boardOffset = boardOffset;

    auto resizeAndReposition = [&](auto& objects) {
        for (auto& obj : objects) {
            sf::Vector2f newPos = obj->getPosition();
            newPos.x = (newPos.x / obj->getSize().x) * newSize.x + m_boardOffset.x;
            newPos.y = (newPos.y / obj->getSize().y) * newSize.y + m_boardOffset.y;
            obj->setSize(newSize);
            obj->setPosition(newPos);
        }
        };

    resizeAndReposition(staticObjects);
    resizeAndReposition(movableObjects);
    resizeAndReposition(bombs);
}

void ObjectManager::addMovable(std::unique_ptr<MovableObject> obj) {
    movableObjects.push_back(std::move(obj));
}

Player* ObjectManager::getPlayer() const {
    return dynamic_cast<Player*>(movableObjects.at(0).get());
}

std::unique_ptr<Player> ObjectManager::releasePlayer() {
    return std::unique_ptr<Player>(static_cast<Player*>(movableObjects.at(0).release()));
}

bool ObjectManager::isPlayerAtDoor() const {
    for (const auto& obj : staticObjects) {
        if (dynamic_cast<Door*>(obj.get())) {
            if (obj->getBounds().intersects(getPlayer()->getBounds())) {
                return true;
            }
        }
    }
    return false;
}

