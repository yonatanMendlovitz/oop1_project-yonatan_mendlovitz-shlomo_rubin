#include "GameManager.h"
#include <SFML/Graphics.hpp>
//#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ObjectManager.h"
#include "Wall.h"
#include "Player.h"
#include "Guard.h"
#include "Bomb.h"

int main() {
	auto a = GameManager();
	a.run();
	return 0;
}
