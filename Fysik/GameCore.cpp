#include "GameCore.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include <math.h>

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
	if (HitTest(ball, ground.dirt1) == 1  || HitTest(ball, ground.dirt2) == 1  || HitTest(ball, ground.grass2) == 1)
		HitGround(ball, Vector2f(0.0f, -1.0f));

	if (HitTest(ball, ground.dirt3) == 1)	//OBS! dirt3 har 2 sidor
		HitGround(ball, Vector2f(-1.0f, 0.0f));

	if (HitTest(ball, water.waterRectangle) == 1)
		HitWater(ball, water);

	return 0;
}

//http://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection/402010#402010

int GameCore::HitTest(Ball ball, RectangleShape sq)
{
	float r = ball.ballShape.getRadius();
	Vector2f ballPos = ball.realPosition;

	Vector2f sqPos = sq.getPosition();
	sqPos.x = sqPos.x + sq.getSize().x / 2;
	sqPos.y = sqPos.y + sq.getSize().y / 2;

	Vector2f HitTestDis = { abs(ballPos.x - sqPos.x), abs(ballPos.y - sqPos.y) };

	std::cout << sq.getSize().x << std::endl;

	if (HitTestDis.x > ((sq.getSize().x) / 2 + r))
		return 0;
	if (HitTestDis.y > (sq.getSize().y / 2 + r))
		return 0;

	if (HitTestDis.x <= (sq.getSize().x / 2))
		return 1;
	if (HitTestDis.y <= (sq.getSize().y / 2))
		return 1;

	return 2;
}

void GameCore::HitGround(Ball ball, Vector2f normal)
{
	Vector2f dir = { ball.ballShape.getPosition().x - ball.direction.x, ball.ballShape.getPosition().y - ball.direction.y };
	dir.x = -dir.x / abs(dir.x + dir.y);
	dir.y = -dir.y / abs(dir.x + dir.y);

	float angle = ((acos(dir.x*normal.x + dir.y*normal.y))/180)*3.1415f;

	ball.speedY = -ball.speedY;
	//ball.startSpeedY = -ball.startSpeedY*5;
	totalTime = 0;
}

void GameCore::HitWater(Ball ball, Water water){
	ball.densityMedium = 1000.0f;
}