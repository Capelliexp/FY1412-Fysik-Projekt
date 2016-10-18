#pragma once
#ifndef GAMECORE_HPP
#define GAMECORE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Ball.h"
#include "Water.h"
#include "Ground.h"
#include "Sky.h"

using namespace sf;

class GameCore : public Drawable {
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	bool gameOver;
	long double totalTime;
	bool waterMode;

	Ball canonBall;
	Water waterPool;
	Ground allGround;
	Sky skyBox;

	GameCore();
	~GameCore();
	bool Update(float dt);
	int CollisionTest(Ground allGround, Water waterPool);
	int HitTest(RectangleShape sq);
	void HitGround(Vector2f normal);
	void HitWater();
};
#endif