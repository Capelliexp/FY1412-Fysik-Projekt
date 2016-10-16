#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Ball.h"

Ball::Ball() {
	startPosX = 50.0f;
	startPosY = 350 - 8.0f;
	startSpeedX = 250.0f;
	startSpeedY = 40.0f;
	spin = 0.0f;
	radius = 0.085f;
	weight = 25.0f;
	materialFriction = 0.0f;
	speedX = 1.0f;
	speedY = 1.0f;
	speedTot = 0;

	densityMedium = 1.21f;	//densitet av det MEDIUM som bollen färdas igenom, byt till 1000 i vatten
	viscosity = 0.0000183f;	//viskositet av luft

	CdX = 0.5f;
	CdY = 0.5f;

	ballShape.setRadius(radius*47);
	ballShape.setPosition(startPosX, startPosY);
	ballShape.setFillColor(sf::Color(255, 0, 0));

	canonTex.loadFromFile("../textures/canonball.png");
	const Texture *tex1 = &canonTex;

	ballShape.setTexture(&canonTex);
}

Ball::~Ball() {
}

void Ball::update(float dt, long double totalTime){
	//ReX = (densityMedium*radius * 2 / viscosity)*speedX;		//ändra viscosity när bollen är i vatten
	//ReY = (densityMedium*radius * 2 / viscosity)*speedY;

	//SphereDragCoefficienCalc();
	
	if (speedX >= 0)
		airResX = -0.5f*CdX*densityMedium*(radius*radius*3.14f)*speedX*speedX;	//ändra densityMedium när bollen är i vatten
	else
		airResX = -0.5f*CdX*densityMedium*(radius*radius*3.14f)*speedX*speedX;

	if(speedY>=0)
		airResY = -0.5f*CdY*densityMedium*(radius*radius*3.14f)*speedY*speedY;
	else
		airResY = 0.5f*CdY*densityMedium*(radius*radius*3.14f)*speedY*speedY;
	

	std::cout << "airResX: " << airResX*dt << std::endl;
	std::cout << "airResY: " << airResY*dt << std::endl;

	sf::Vector2f speedCalcTemp = ballShape.getPosition();	//måste vara innan .move

	ballShape.move((startSpeedX*dt) + ((airResX*dt)/weight), (-startSpeedY*dt) + (9.82f*dt*(totalTime*totalTime)/2) - ((airResY*dt)/weight));

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