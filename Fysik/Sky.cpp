#include <SFML/Graphics.hpp>
#include <vector>
#include "Sky.h"

Sky::Sky() {
	skyRectangle.setSize(sf::Vector2f(1280, 350));
	skyRectangle.setFillColor(sf::Color(255, 255, 255));
	skyRectangle.setPosition(0, 0);

	skyTex.loadFromFile("../textures/clouds.jpg");
	const Texture *tex1 = &skyTex;

	skyRectangle.setTexture(&skyTex);
}

Sky::~Sky() {
}

void Sky::draw(RenderTarget& target, RenderStates states) const {
	target.draw(skyRectangle);
}