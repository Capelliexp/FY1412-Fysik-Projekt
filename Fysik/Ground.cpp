#include <SFML/Graphics.hpp>
#include <vector>
#include "Ground.h"

Ground::Ground(){
	grass1.setSize(sf::Vector2f(500, 10));	//bredd, h�jd
	grass1.setFillColor(sf::Color(50, 255, 50));
	grass1.setPosition(0, 343);

	grass2.setSize(sf::Vector2f(380, 10));	//bredd, h�jd
	grass2.setFillColor(sf::Color(50, 255, 50));
	grass2.setPosition(900, 343);

	//-----

	dirt1.setSize(sf::Vector2f(500, 367));	//bredd, h�jd
	dirt1.setFillColor(sf::Color(100, 100, 100));
	dirt1.setPosition(0, 353);

	dirt2.setSize(sf::Vector2f(400, 200));	//bredd, h�jd
	dirt2.setFillColor(sf::Color(100, 100, 100));
	dirt2.setPosition(500, 550);

	dirt3.setSize(sf::Vector2f(380, 367));	//bredd, h�jd
	dirt3.setFillColor(sf::Color(100, 100, 100));
	dirt3.setPosition(900, 353);

	//-----

	grassTex.loadFromFile("../textures/grass2.png");
	const Texture *tex1 = &grassTex;

	dirtTex.loadFromFile("../textures/dirt.jpg");
	const Texture *tex2 = &dirtTex;

	grass1.setTexture(&grassTex);
	grass2.setTexture(&grassTex);

	dirt1.setTexture(&dirtTex);
	dirt2.setTexture(&dirtTex);
	dirt3.setTexture(&dirtTex);
}

Ground::~Ground()
{

}

//f�r r�d understrykning p� draw av n�gon anledning - du hade fel parametrar
void Ground::draw(RenderTarget& target, RenderStates states) const {
	target.draw(grass1);
	target.draw(grass2);

	target.draw(dirt1);
	target.draw(dirt2);
	target.draw(dirt3);
}