#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include "Ball.h"

Ball::Ball() {
	startPosX = 50.0f;
	startPosY = 350 - 8.0f - 30.0f;
	startSpeedX = 40.0f;
	startSpeedY = 40.0f;
	spin = 0.0f;
	radius = 0.085f;
	weight = 25.0f;
	materialFriction = 0.0f;
	speedX = startSpeedX;
	speedY = startSpeedY;
	speedTot = 0;
	speedTerminal = 0.0f;
	moveX = 0.0f;
	moveY = 0.0f;

	densityMedium = 1.21f;		//densitet av det MEDIUM som bollen färdas igenom, byt till 1000 i vatten
	viscosity = 0.0000183f;		//viskositet av luft

	CdX = 0.5f;
	CdY = 0.5f;

	ballShape.setRadius(radius*100);
	ballShape.setPosition(startPosX, startPosY);
	ballShape.setFillColor(sf::Color(255, 0, 0));

	canonTex.loadFromFile("../textures/canonball.png");
	const Texture *tex1 = &canonTex;

	ballShape.setTexture(&canonTex);
}

Ball::~Ball() {
}

void Ball::update(float dt, long double totalTime, bool waterModeCollision){
	//ReX = (densityMedium*radius * 2 / viscosity)*speedX;		//ändra viscosity & densityMedium när bollen är i vatten
	//ReY = (densityMedium*radius * 2 / viscosity)*speedY;

	//SphereDragCoefficienCalc();

	if (speedX >= 0)
		airResX = -0.5f*CdX*densityMedium*(radius*radius*3.14f)*speedX*speedX;	//ändra densityMedium när bollen är i vatten
	else
		airResX = 0.5f*CdX*densityMedium*(radius*radius*3.14f)*speedX*speedX;

	if(speedY>=0)
		airResY = -0.5f*CdY*densityMedium*(radius*radius*3.14f)*speedY*speedY;
	else
		airResY = 0.5f*CdY*densityMedium*(radius*radius*3.14f)*speedY*speedY;
	

	std::cout << "dt: " << dt << std::endl;
	std::cout << "airResX: " << airResX << std::endl;
	std::cout << "airResY: " << airResY << std::endl;
	std::cout << "speedX: " << speedX << std::endl;
	std::cout << "speedY: " << speedY << std::endl;

	direction = ballShape.getPosition();	//måste vara innan .move

	//moveX = (startSpeedX*dt) + ((airResX*dt) / weight);
	//moveY = (-startSpeedY*dt) + (9.82f*dt*(totalTime*totalTime) / 2) - ((airResY*dt) / weight);
	
	moveX = startPosX + (startSpeedX*totalTime) /*+ (airResX*dt)/weight*/;
	if (startSpeedX > 10e-4)
	{
		startSpeedX = startSpeedX + (airResX / weight)*dt;
		if (abs((airResX / weight)*dt) > abs(startSpeedX))
		{
			startSpeedX = 0.0f;
			startPosX = ballShape.getPosition().x;
		}
	}
	else
		startSpeedX = 0.0f;
	//moveY = startPosY - (startSpeedY*totalTime) + (0.5f * 9.82f * totalTime * totalTime); //https://en.wikipedia.org/wiki/Free_fall  https://en.wikipedia.org/wiki/Terminal_velocity#Examples

	if (waterModeCollision == false) {
		speedTerminal = sqrt((2 * weight*9.82) / (densityMedium*CdX*radius*radius*3.1415));
		moveY = startPosY - startSpeedY*totalTime + (speedTerminal*speedTerminal / 9.82)*log(cosh((9.82*totalTime) / (speedTerminal)));
	}
	/*else {
		moveY = 0;
	}*/

	

	ballShape.setPosition(moveX, moveY);
	//ballShape.move(((airResX*dt) / weight), ((airResY*dt) / weight));

	//startSpeedX = startSpeedX + ((airResX*dt) / weight);	//ny
	//startSpeedY = startSpeedY - ((airResY*dt) / weight);
	if (startSpeedX != 0.0f)
		speedX = (ballShape.getPosition().x - direction.x)*(1 / dt);
	else
		speedX = 0.0f;
	speedY = (ballShape.getPosition().y - direction.y)*(1 / dt);
	//speedTot = sqrt((speedX*speedX) + (speedY*speedY))+1.0e-8;

	realPosition.x = ballShape.getPosition().x + ballShape.getRadius() / 2;
	realPosition.y = ballShape.getPosition().y + ballShape.getRadius() / 2;
}

void Ball::draw(RenderTarget& target, RenderStates states) const {
	target.draw(ballShape);
}

void Ball::SphereDragCoefficienCalc(){
	for (int i = 0; i < 2; i++) {	//beräkning av Cd
		float Cd;
		float Re = ReX;
		if (i == 1)
			Re = ReY;

		if (Re < 100)	//approximationer
			Cd = 1.25f;
		else if (Re < 1000)
			Cd = 0.75f;
		else if (Re < 100000)
			Cd = 0.5f;
		else if (Re < 316227)
			Cd = 0.1f;
		else
			Cd = 0.25f;

		if (i == 1)
			CdY = Cd;
		else
			CdX = Cd;
	}
}