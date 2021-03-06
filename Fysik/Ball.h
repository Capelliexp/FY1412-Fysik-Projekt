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
	float tempV;
	float startPosY;
	float startSpeedX;
	float startSpeedY;
	float spin;
	float tempS;
	float radius;
	float weight;
	float friction;
	float restitution;

	bool roll;

	float densityMedium;
	float viscosity;

	float speedX;
	float speedY;
	float speedTot;
	float speedTerminal;

	float moveY;
	float moveX;

	float ReX;
	float ReY;
	float CdX;
	float CdY;

	float windX;
	float windY;

	long double airResX;
	long double airResY;

	Vector2f direction;
	Vector2f realPosition;

	//https://www.grc.nasa.gov/www/k-12/airplane/dragsphere.html

	CircleShape ballShape;
	Texture canonTex;

	Ball();
	~Ball();

	void update(float dt, long double totalTime, bool waterModeCollision);
	void SphereDragCoefficienCalc();
};
#endif