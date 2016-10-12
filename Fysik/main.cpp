#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include "GameCore.hpp"

using namespace sf;

int main() {
	GameCore game;

	RenderWindow window(VideoMode(800, 600), "Fysik Projekt");
	Clock gameTime;
	int fpsCounter = 0;

	bool gameOver = false;
	std::string endBlock;

	while (window.isOpen()){
		fpsCounter++;

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

		if (fpsCounter > 60) {	//begränsar FPS men ser till att game.Update() kan köras hur snabbt den vill
			window.clear();
			window.draw(game);
			window.display();
			fpsCounter = 0;
		}
	}

	if (gameOver == true) {
		std::cout << std::endl << std::endl << std::endl << "You completed the game! Congratulations" << std::endl;
		std::cin >> endBlock;
	}
	return 0;
}