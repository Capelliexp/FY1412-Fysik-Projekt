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
	float materialFriction;

	sf::CircleShape ballShape;

	Ball();
	~Ball();

	void update(float dt);
};
#endif

