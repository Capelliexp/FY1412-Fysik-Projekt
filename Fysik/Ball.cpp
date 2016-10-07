#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.hpp"

Ball::Ball() {
	startPosX = 5;
	startPosY = 5;
	accelerationX = 0;
	accelerationY = 0;
	weight = 5;
	spin = 0;
	radius = 1;
}

Ball::~Ball() {
}

float* CalcNewPos(float dt) {	//returnerar array av 2, x & y
	float returnValues[2];

	return returnValues;
}
