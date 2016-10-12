#pragma once
#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Ball : public Drawable {
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;
public:
	float startPosX;
	float startPosY;
	float accelerationX;
	float accelerationY;
	float spin;
	float radius;
	float weight;
	float density;
	float materialFriction;

	float densityMedium;
	float viscosity;

	float speedX;
	float speedY;
	float speedTot;

	float ReX;
	float ReY;
	float CdX;
	float CdY;

	float airResX;
	float airResY;

	//https://www.grc.nasa.gov/www/k-12/airplane/dragsphere.html

	CircleShape ballShape;

	Ball();
	~Ball();

	void update(float dt, long double totalTime);
	void SphereDragCoefficienCalc();
};
#endif