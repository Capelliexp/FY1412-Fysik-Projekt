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
	if (Bonk(ball, ground.dirt1) == 1)
		Hit(ball, Vector2f(0.0f, -1.0f));
	//else if (Bonk(ball, ground.dirt1) == 2)
	//{
	//	std::cout << "weird yao454545454545454545445445" << std::endl;
	//	std::cout << "weird yao454545454545454545445445" << std::endl;
	//	std::cout << "weird yao454545454545454545445445" << std::endl;
	//	std::cout << "weird yao454545454545454545445445" << std::endl;
	//	std::cout << "weird yao454545454545454545445445" << std::endl;
	//	std::cout << "weird yao454545454545454545445445" << std::endl;
	//}

	


	return 0;
}

//http://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection/402010#402010

int GameCore::Bonk(Ball ball, RectangleShape sq)
{
	float r = ball.ballShape.getRadius();
	Vector2f ballPos = ball.realPosition;

	Vector2f sqPos = sq.getPosition();
	sqPos.x = sqPos.x + sq.getSize().x / 2;
	sqPos.y = sqPos.y + sq.getSize().y / 2;

	Vector2f bonkDis = { abs(ballPos.x - sqPos.x), abs(ballPos.y - sqPos.y) };

	std::cout << sq.getSize().x << std::endl;

	if (bonkDis.x > ((sq.getSize().x) / 2 + r))
		return 0;
	if (bonkDis.y > (sq.getSize().y / 2 + r))
		return 0;

	if (bonkDis.x <= (sq.getSize().x / 2))
		return 1;
	if (bonkDis.y <= (sq.getSize().y / 2))
		return 1;

	return 2;
}

void GameCore::Hit(Ball ball, Vector2f normal)
{
	Vector2f dir = { ball.ballShape.getPosition().x - ball.direction.x, ball.ballShape.getPosition().y - ball.direction.y };
	dir.x = -dir.x / abs(dir.x + dir.y);
	dir.y = -dir.y / abs(dir.x + dir.y);

	float angle = ((acos(dir.x*normal.x + dir.y*normal.y))/180)*3.1415f;

	ball.speedY = -ball.speedY;
	//ball.startSpeedY = -ball.startSpeedY*5;
	totalTime = 0;
}
