#include <SFML/Graphics.hpp>
#include <vector>
#include "Water.h"

Water::Water() {
	temp = 20;	//behaglig badtemperatur

	waterRectangle.setSize(sf::Vector2f(100, 50));	//bredd, höjd
	waterRectangle.setFillColor(sf::Color::Blue);
	waterRectangle.setPosition(10, 20);				//koordinater på mitten?
}

Water::~Water() {
}

void Water::draw(RenderTarget& target, RenderStates states) const {
	target.draw(waterRectangle);
}