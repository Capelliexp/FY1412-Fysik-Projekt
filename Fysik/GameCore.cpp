#include "GameCore.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>

using namespace sf;

GameCore::GameCore() {	//skapa alla objekt med egenskaper
	gameOver = false;
	totalTime = 0;
}

GameCore::~GameCore() {
}

bool GameCore::Update(float dt) {	//Detta händer per frame / logic
	totalTime += dt;

	canonBall.update(dt, totalTime);

	return (gameOver);
}

void GameCore::draw(RenderTarget& target, RenderStates states) const {	//detta ritas per frame / graphics

	//OBS! den som ritas ut sist ritas överst
	target.draw(waterPool);
	target.draw(allGround);
	target.draw(canonBall);
}
