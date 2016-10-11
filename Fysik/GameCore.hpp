#pragma once
#ifndef GAMECORE_HPP
#define GAMECORE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Ball.h"
#include "Water.h"
#include "Ground.h"

using namespace sf;

class GameCore : public Drawable {
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	bool gameOver;
	long double totalTime;

	Ball canonBall;
	Water waterPool;
	Ground allGround;

	GameCore();
	~GameCore();
	bool Update(float dt);
};
#endif