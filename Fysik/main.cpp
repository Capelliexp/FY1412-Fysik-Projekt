#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include "GameCore.hpp"

using namespace sf;

int main() {
	GameCore game;

	RenderWindow window(VideoMode(800, 600), "Fysik Projekt");
	window.setFramerateLimit(30);
	Clock gameTime;

	bool gameOver = false;
	std::string endBlock;

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		gameOver = game.Update(gameTime.restart().asSeconds());

		if (gameOver == true) {
			break;
			window.clear();
			window.close();
		}

		window.clear();
		window.draw(game);
		window.display();
	}

	if (gameOver == true) {
		std::cout << std::endl << std::endl << std::endl << "You completed the game! Congratulations" << std::endl;
		std::cin >> endBlock;
	}
	return 0;
}