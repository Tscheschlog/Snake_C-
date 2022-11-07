#include "GameBoard.h"
#include <iostream>
#include <string>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <stdlib.h> 
#include <time.h>  


SnakeGameBoard::SnakeGameBoard() {
	gameWindow = new sf::RenderWindow(sf::VideoMode(), "Snake!", sf::Style::Fullscreen);
	gameWindow->setFramerateLimit(12);

	BoardSetUp(*gameWindow);

	snake = new Snake();
	apple = new Apple();

	gameBoardWidth = gameBoard.getGlobalBounds().width;
	gameBoardHeight = gameBoard.getGlobalBounds().height;

	gameDisplay(*gameWindow);
}

void foundApple(Apple& apple,Snake& snake) {

    if (apple.xPos == snake.getHeadPos().xPos && apple.yPos == snake.getHeadPos().yPos) {
        apple.newApple();
        snake.appleEaten();
    }

}

void SnakeGameBoard::gameDisplay(sf::RenderWindow& Game) {


	while (Game.isOpen()) {

		drawBoard(Game);

		sf::Event eventGame;
		while (Game.pollEvent(eventGame)) {

            snake->movementHandler(eventGame);

			if (eventGame.type == sf::Event::KeyPressed && eventGame.key.code == sf::Keyboard::Escape)
				Game.close();
		}
		foundApple(*apple, *snake);
	}
}

void SnakeGameBoard::BoardSetUp(sf::RenderWindow& Game) {
	grassTexture.loadFromFile("../Images/Grass.jpg");
	gameBoard.setTexture(grassTexture);

	float sizeX = .75*float(Game.getSize().x) / float(grassTexture.getSize().x);
	float sizeY = .75*float(Game.getSize().y) / float(grassTexture.getSize().y);

	gameBoard.setScale((sf::Vector2f(sizeX, sizeY)));
	gameBoard.setPosition(Game.getSize().x / 8.f, Game.getSize().y / 8.f);
}


void SnakeGameBoard::drawBoard(sf::RenderWindow& Game) {
	Game.clear(sf::Color::Black);
	Game.draw(gameBoard);

	apple->render(Game);

	snake->render(Game);
	snake->updateSnakeBody();
	
	Game.display();
}



