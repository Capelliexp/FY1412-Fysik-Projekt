#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include "GameCore.hpp"

using namespace sf;

int main() {
	GameCore game;

	RenderWindow window(VideoMode(1280, 720), "Fysik Projekt");
	Clock gameTime;
	Clock frameTime;

	bool gameOver = false;
	std::string endBlock;

	while (window.isOpen()){

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		gameOver = game.Update(gameTime.restart().asSeconds());
		std::cout << "ny update" << std::endl;

		if (gameOver == true) {
			break;
			window.clear();
			window.close();
		}

		if (frameTime.getElapsedTime().asSeconds() >= 1/60) {
			std::cout << "ny frame" << std::endl << std::endl;
			window.clear();
			window.draw(game);
			window.display();
			frameTime.restart();
		}
	}

	if (gameOver == true) {
		std::cout << std::endl << std::endl << std::endl << "You completed the game! Congratulations" << std::endl;
		std::cin >> endBlock;
	}
	return 0;
}