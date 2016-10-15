#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Ball.h"

Ball::Ball() {
	startPosX = 50.0f;
	startPosY = 350 - 8.0f;
	accelerationX = 40.0f;
	accelerationY = 40.0f;
	spin = 0.0f;
	radius = 4.0f;
	weight = 5.0f;
	density = 1.0f;
	materialFriction = 0.0f;

	speedX = 1.0f;
	speedY = 1.0f;
	speedTot = 0;

	densityMedium = 1.0f;	//densitet av det MEDIUM som bollen färdas igenom
	viscosity = 0.0000183f;	//viskositet av luft

	ballShape.setRadius(radius);
	ballShape.setPosition(startPosX, startPosY);
	ballShape.setFillColor(sf::Color(255, 0, 0));
}

Ball::~Ball() {
}

void Ball::update(float dt, long double totalTime){
	ReX = (density*radius * 2 / viscosity)*speedX;		//ändra viscosity när bollen är i vatten
	ReY = (density*radius * 2 / viscosity)*speedY;

	SphereDragCoefficienCalc();

	airResX = 0.5f*CdX*densityMedium*(radius*radius*3.14f)*speedX;	//ändra densityMedium när bollen är i vatten
	airResY = 0.5f*CdY*densityMedium*(radius*radius*3.14f)*speedY;
	//std::cout << "airResX: " << airResX << std::endl;
	//std::cout << "airResY: " << airResY << std::endl;

	sf::Vector2f speedCalcTemp = ballShape.getPosition();	//måste vara innan .move

	ballShape.move(accelerationX*dt/* - airResX*dt*/, -accelerationY*dt + 9.82f*dt*totalTime/* + airResY*dt*/);

	speedX = (speedCalcTemp.x - ballShape.getPosition().x)*(1 / dt);
	speedY = (speedCalcTemp.y - ballShape.getPosition().y)*(1 / dt);
	//speedTot = sqrt((speedX*speedX) + (speedY*speedY));
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