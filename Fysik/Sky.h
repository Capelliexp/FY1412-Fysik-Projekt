#pragma once
#ifndef SKY_H
#define SKY_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Sky : public Drawable
{
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;

public:
	RectangleShape skyRectangle;
	Texture skyTex;

	Sky();
	~Sky();
};
#endif