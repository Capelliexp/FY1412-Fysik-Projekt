#pragma once
#ifndef WATER_H
#define WATER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Water : public Drawable
{
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	bool collision;
	int temp;

	RectangleShape waterRectangle;
	Texture waterTex;

	Water();
	~Water();
};
#endif