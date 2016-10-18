#include <SFML/Graphics.hpp>
#include <vector>
#include "Ground.h"

Ground::Ground(){
	grass1.setSize(sf::Vector2f(500, 10));
	grass1.setFillColor(sf::Color(50, 255, 50));
	grass1.setPosition(0, 343);

	grass2.setSize(sf::Vector2f(380, 10));
	grass2.setFillColor(sf::Color(50, 255, 50));
	grass2.setPosition(900, 343);

	//-----

	dirt1.setSize(sf::Vector2f(500, 367));
	dirt1.setFillColor(sf::Color(100, 100, 100));
	dirt1.setPosition(0, 353);

	dirt2.setSize(sf::Vector2f(400, 200));
	dirt2.setFillColor(sf::Color(100, 100, 100));
	dirt2.setPosition(500, 550);

	dirt3.setSize(sf::Vector2f(380, 367));
	dirt3.setFillColor(sf::Color(100, 100, 100));
	dirt3.setPosition(900, 353);

	//-----

	goal.setSize(sf::Vector2f(70, 70));	//byts denna måste explosion också flyttas
	goal.setPosition(1000, 290);

	//-----

	grassTex.loadFromFile("../textures/grass2.png");
	const Texture *tex1 = &grassTex;

	dirtTex.loadFromFile("../textures/dirt.jpg");
	const Texture *tex2 = &dirtTex;

	targetTex.loadFromFile("../textures/target.png");
	const Texture *tex3 = &targetTex;

	grass1.setTexture(&grassTex);
	grass2.setTexture(&grassTex);

	dirt1.setTexture(&dirtTex);
	dirt2.setTexture(&dirtTex);
	dirt3.setTexture(&dirtTex);

	goal.setTexture(&targetTex);
}

Ground::~Ground()
{

}

//får röd understrykning på draw av någon anledning - du hade fel parametrar
void Ground::draw(RenderTarget& target, RenderStates states) const {
	target.draw(grass1);
	target.draw(grass2);

	target.draw(dirt1);
	target.draw(dirt2);
	target.draw(dirt3);

	target.draw(goal);
}