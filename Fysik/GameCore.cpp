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
	CollisionTest(canonBall, allGround, waterPool);
	return (gameOver);
}

void GameCore::draw(RenderTarget& target, RenderStates states) const {	//detta ritas per frame / graphics

	//OBS! den som ritas ut sist ritas överst
	target.draw(skyBox);
	target.draw(waterPool);
	target.draw(allGround);
	target.draw(canonBall);
}

int GameCore::CollisionTest(Ball ball, Ground ground, Water water)
{
	//float circleDistanceX;
	return 0;
}

int GameCore::Bonk(CircleShape ball, RectangleShape sq)
{
	float r = ball.getRadius();
	Vector2f ballPos = ball.getPosition();
	Vector2f sqPos = sq.getPosition();

	 float bonkDisX = abs(ballPos.x - sqPos.x);
	 float bonkDisY = abs(ballPos.y - sqPos.y);

	 return 0;
}
