#include <SFML/Graphics.hpp>
#include <vector>
#include "Water.h"

Water::Water() {
	temp = 20;	//behaglig badtemperatur

	waterRectangle.setSize(sf::Vector2f(400, 200));	//bredd, höjd
	waterRectangle.setFillColor(sf::Color(50, 50, 255));
	waterRectangle.setPosition(200, 350);			//koordinater på övre-vänstra hörnet
}

Water::~Water() {
}

void Water::draw(RenderTarget& target, RenderStates states) const {
	target.draw(waterRectangle);
}