#include <SFML/Graphics.hpp>
#include <vector>
#include "Ground.hpp"

Ground::Ground()
{
	//Rita upp marken? - sätt standardvärden på marken, om de senare ska ändras sätts det i en update-funktion
	//http://www.sfml-dev.org/tutorials/2.0/graphics-shape.php
	//http://www.sfml-dev.org/documentation/2.0/classsf_1_1RectangleShape.php
}

Ground::~Ground()
{

}

//får röd understrykning på draw av någon anledning - du hade fel parametrar
void Ground::draw(RenderTarget& target, RenderStates states) const {
	target.draw(g1);
	target.draw(g2);

	target.draw(w1);
	target.draw(w2);
	target.draw(w3);
}