#include "GameCore.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>

using namespace sf;

GameCore::GameCore() {	//skapa alla objekt med egenskaper
	gameOver = false;
	//Ball canonBall = new Ball();
}

GameCore::~GameCore(){
}

bool GameCore::Update(float dt) {	//Detta h�nder per frame / logic
	return (gameOver);
}

void GameCore::draw(RenderTarget& target, RenderStates states) const {	//detta ritas per frame / graphics

	//target.draw(canonBall);
}
