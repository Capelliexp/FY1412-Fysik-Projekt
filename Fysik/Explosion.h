#pragma once
#pragma once
#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Explosion : public Drawable {
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;
public:

	CircleShape explosionShape;
	Texture boomTex;

	Explosion();
	~Explosion();

	void update(bool showFigure);
};
#endif