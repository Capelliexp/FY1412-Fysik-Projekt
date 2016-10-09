#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.hpp"

Ball::Ball() {
	startPosX = 0;
	startPosY = 0;
	accelerationX = 0;
	accelerationY = 0;
	spin = 0;
	radius = 0;
	weight = 0;
	materialFriction = 0;
}

Ball::~Ball() {
}

float* CalcNewPos(float dt) {	//returnerar array av 2, x & y
	float returnValues[2];

	return returnValues;
}
