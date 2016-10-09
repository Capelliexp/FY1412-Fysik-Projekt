#pragma once
#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Ball : public Drawable {
public:
	float startPosX;
	float startPosY;
	float accelerationX;
	float accelerationY;
	float spin;
	float radius;
	float weight;
	float materialFriction;

	Ball();
	~Ball();

	float* CalcNewPos(float dt);	//returnerar array av 2, x & y
};
#endif

