#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"

Ball::Ball() {
	startPosX = 50;
	startPosY = 350 - 8;
	accelerationX = 40;
	accelerationY = 40;
	spin = 0;
	radius = 0;
	weight = 0;
	materialFriction = 0;

	ballShape.setRadius(4);
	ballShape.setPosition(startPosX, startPosY);
	ballShape.setFillColor(sf::Color(255, 0, 0));
}

Ball::~Ball() {
}

void Ball::update(float dt, long double totalTime){
	ballShape.move(accelerationX*dt, -accelerationY*dt + 9.82*dt*totalTime);	//säkert fel...
}

void Ball::draw(RenderTarget& target, RenderStates states) const {
	target.draw(ballShape);
}