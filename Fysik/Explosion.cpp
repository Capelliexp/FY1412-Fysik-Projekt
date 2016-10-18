#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include "Explosion.h"

Explosion::Explosion() {
	showTexLoop = 0;

	explosionShape.setRadius(0);
	explosionShape.setPosition(1000, 290);

	boomTex.loadFromFile("../textures/explosion.png");
	const Texture *tex1 = &boomTex;

	explosionShape.setTexture(&boomTex);
}

Explosion::~Explosion() {
}

void Explosion::update(bool showFigure){
	if (showFigure == true) {
		explosionShape.setRadius(explosionShape.getRadius() + 20);	//körs 20 gånger
		explosionShape.setPosition(explosionShape.getPosition().x - 20, explosionShape.getPosition().y - 20);
	}
}

void Explosion::draw(RenderTarget& target, RenderStates states) const {
	target.draw(explosionShape);
}