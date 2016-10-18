#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include "Explosion.h"

Explosion::Explosion() {
}

Explosion::~Explosion() {
}

void Explosion::update(bool showFigure) {
}

void Explosion::draw(RenderTarget& target, RenderStates states) const {
	target.draw(explosionShape);
}