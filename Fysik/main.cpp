#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include "GameCore.hpp"
#include <math.h>

using namespace sf;

int main() {
	int speed = 0;
	int angle = 0;
	std::cout << "Ange hastighet: ";
	std::cin >> speed;
	std::cout << "Ange vinkel (grader): ";
	std::cin >> angle;

	float vx = speed * sin(angle * (3.14 / 180));
	float vy = speed * cos(angle * (3.14 / 180));

	GameCore game(vx, vy);

	RenderWindow window(VideoMode(1280, 720), "Fysik Projekt");
	Clock gameTime;
	Clock frameTime;

	int gameOver = 0;
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

		if (gameOver == 1 || gameOver == 2) {
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

	if (gameOver == 1) {
		std::cout << std::endl << std::endl << std::endl << "You missed the target :(" << std::endl;
		std::cin >> endBlock;
	}
	else if (gameOver == 2) {
		std::cout << std::endl << std::endl << std::endl << "Did bonk, made BOOM" << std::endl;
		std::cin >> endBlock;
	}
	return 0;
}