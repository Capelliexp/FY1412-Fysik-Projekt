#pragma once
#ifndef GAMECORE_HPP
#define GAMECORE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Ball.h"
#include "Water.h"
#include "Ground.h"
#include "Sky.h"
#include "Explosion.h"

using namespace sf;

class GameCore : public Drawable {
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	int gameOver;
	long double totalTime;
	bool waterMode;
	bool waterModeCollision;
	int gameOverResPos;
	bool hitTarget;
	float angle;

	Ball canonBall;
	Water waterPool;
	Ground allGround;
	Sky skyBox;
	Explosion endPoof;

	GameCore(float vx, float vy);
	~GameCore();
	int Update(float dt);
	int TestGameOver();

	int CollisionTest(Ground allGround, Water waterPool);
	int HitTest(RectangleShape sq);
	void HitGround(Vector2f normal);
	void HitWater();
	void HitTarget();
};
#endif