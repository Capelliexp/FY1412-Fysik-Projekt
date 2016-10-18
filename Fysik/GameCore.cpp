#include "GameCore.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include <math.h>

using namespace sf;

GameCore::GameCore(float vx, float vy) {	//skapa alla objekt med egenskaper
	canonBall.startSpeedX = vx;
	canonBall.startSpeedY = vy;
	
	gameOver = 0;
	totalTime = 0;
	waterMode = false;
	waterModeCollision = false;
	gameOverResPos = 0;
	hitTarget = false;
}

GameCore::~GameCore() {
}

int GameCore::Update(float dt) {	//Detta händer per frame / logic
	totalTime += dt;

	//canonBall.densityMedium = 1000;

	canonBall.update(dt, totalTime, waterModeCollision);
	endPoof.update(hitTarget);

	CollisionTest(allGround, waterPool);
	gameOver = TestGameOver();

	return (gameOver);
}

int GameCore::TestGameOver() {
	if ((canonBall.speedX == 0 && canonBall.speedY == 0) || hitTarget == true) {
		gameOverResPos++;
		if (gameOverResPos >= 20) {
			if (hitTarget == true)
				return 2;
			else
				return 1;
		}
	}
	return 0;
}

void GameCore::draw(RenderTarget& target, RenderStates states) const {	//detta ritas per frame / graphics

	//OBS! den som ritas ut sist ritas överst
	target.draw(skyBox);
	target.draw(waterPool);
	target.draw(allGround);
	target.draw(canonBall);
	target.draw(endPoof);
}

int GameCore::CollisionTest(Ground ground, Water water)
{
	if (HitTest(ground.dirt1) == 1  || HitTest(ground.dirt2) == 1  || HitTest(ground.grass2) == 1){
		HitGround(Vector2f(0.0f, -1.0f));
	}
	if (HitTest(ground.dirt3) == 1) {	//OBS! dirt3 har 2 sidor
		HitGround(Vector2f(-1.0f, 0.0f));
	}
	if (HitTest(water.waterRectangle) == 1 && waterMode == false) {
		HitWater();
	}
	if (HitTest(ground.goal) == 1) {
		HitTarget();
	}

	return 0;
}

void GameCore::HitTarget() {
	hitTarget = true;
	gameOverResPos = 2;
	canonBall.startSpeedX = 0.0f;
	canonBall.startSpeedY = 0.0f;
}

//http://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection/402010#402010

int GameCore::HitTest(RectangleShape sq)
{
	float r = canonBall.ballShape.getRadius();
	Vector2f ballPos = canonBall.realPosition;

	Vector2f sqPos = sq.getPosition();
	sqPos.x = sqPos.x + sq.getSize().x / 2;
	sqPos.y = sqPos.y + sq.getSize().y / 2;

	Vector2f HitTestDis = { abs(ballPos.x - sqPos.x), abs(ballPos.y - sqPos.y) };

	//std::cout << sq.getSize().x << std::endl;

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

void GameCore::HitGround(Vector2f normal){
	if (waterMode == false) {
		Vector2f dir = { canonBall.ballShape.getPosition().x - canonBall.direction.x, canonBall.ballShape.getPosition().y - canonBall.direction.y };
		angle = abs(dir.x + dir.y);
		dir.x = -dir.x / angle;
		dir.y = -dir.y / angle;

		//angle = abs(dir.x + dir.y);
		//angle = abs(normal.x + normal.y);

		angle = dir.x*normal.x + dir.y*normal.y;
		angle = acos(angle);
		angle = (angle * 180)/3.1415f;

		canonBall.startPosX = canonBall.ballShape.getPosition().x;
		canonBall.startPosY = canonBall.ballShape.getPosition().y;

		if (abs(angle) < 45)
			waterModeCollision = true;
		else if(45 <= abs(angle) < 75 )
			canonBall.startSpeedY = canonBall.restitution*canonBall.startSpeedY; //bortser från friktion
		else
		{
			canonBall.startSpeedY = 0.0f;
		}


		//canonBall.speedY = -canonBall.speedY;
		//canonBall.startSpeedY = -canonBall.startSpeedY*5;
		//canonBall.ballShape.move(normal.x, normal.y);
		totalTime = 0;
	}
	else {
		waterModeCollision = true;
	}

	
}

void GameCore::HitWater(){
	waterMode = true;
	canonBall.densityMedium = 1000.0f;
	canonBall.viscosity = 1.002f;

	canonBall.startPosX = canonBall.ballShape.getPosition().x;
	canonBall.startPosY = canonBall.ballShape.getPosition().y;

	canonBall.speedX /= 10;
	canonBall.speedY /= 10;

	canonBall.startSpeedX /= 6;
	canonBall.startSpeedY /= -10;

	totalTime = 0;

}