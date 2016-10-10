#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"

Ball::Ball() {
	startPosX = 0;
	startPosY = 0;
	accelerationX = 0;
	accelerationY = 0;
	spin = 0;
	radius = 0;
	weight = 0;
	materialFriction = 0;

	ballShape.setRadius(5);
	ballShape.setOrigin(20.0f, 20.0f);
	ballShape.setFillColor(sf::Color(100, 250, 50));
}

Ball::~Ball() {
}

void Ball::update(float dt) {
}

void Ball::draw(RenderTarget& target, RenderStates states) const {

	target.draw(ballShape);
}