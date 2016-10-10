#include <SFML/Graphics.hpp>
#include <vector>
#include "Ground.h"

Ground::Ground()
{
	//Rita upp marken? - s�tt standardv�rden p� marken, om de senare ska �ndras per frame s�tts det i en update-funktion
	//http://www.sfml-dev.org/tutorials/2.0/graphics-shape.php
	//http://www.sfml-dev.org/documentation/2.0/classsf_1_1RectangleShape.php

	//n�r du har skapat marken kan du ta en titt p� Water() och se till att vattnet "fyller" poolen i mitten av banan
}

Ground::~Ground()
{

}

//f�r r�d understrykning p� draw av n�gon anledning - du hade fel parametrar
void Ground::draw(RenderTarget& target, RenderStates states) const {
	target.draw(g1);
	target.draw(g2);

	target.draw(w1);
	target.draw(w2);
	target.draw(w3);
}