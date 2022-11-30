#include "GameBoard.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <stdlib.h> 
#include <windows.h>
#include <time.h>  


GameBoard::GameBoard(bool isSinglePlayer) {
	gameWindow = new sf::RenderWindow(sf::VideoMode(), "Snake!", sf::Style::Fullscreen);
	gameWindow->setFramerateLimit(12);

	snakeColor1 = Options::snakeColor1;
	snakeColor2 = Options::snakeColor2;


	BoardSetUp(*gameWindow);

	gameBoardWidth = gameBoard.getGlobalBounds().width;
	gameBoardHeight = gameBoard.getGlobalBounds().height;

	snake_1 = new Snake(gameBoard, gameBoardWidth, gameBoardHeight, snakeColor1, isSinglePlayer);
	apple = new Apple(gameBoard, gameBoardWidth, gameBoardHeight);


	if (!isSinglePlayer) {
		snake_2 = new Snake(gameBoard, gameBoardWidth, gameBoardHeight, snakeColor2, !isSinglePlayer);
		gameDisplay_2P(*gameWindow);
	}
	else
		gameDisplay_1P(*gameWindow);
}

void GameBoard::foundApple(Apple& apple,Snake& snake, char &snakeColor) {

    if (apple.appleSprite.getGlobalBounds().contains(snake.getHeadPos().xPos,snake.getHeadPos().yPos)) { //Checks if snake head is in the bounds of the Apple
        apple.newApple(gameBoard,gameBoardWidth,gameBoardHeight);
        snake.appleEaten(snakeColor);
    }

}

void GameBoard::startCountDown_1P(sf::RenderWindow& Game) {

	sf::Font font;
	if (!font.loadFromFile("../Fonts/Points_Font.ttf")) {
		std::cout << "ERROR FONT";
	}
	
	sf::Text countDown;
	countDown.setFont(font);
	countDown.setCharacterSize(400);
	countDown.setFillColor(sf::Color::Red);
	for (int i = 5; i > -1; i--) {

		sf::String count;
		if (i == 0)
			count = "GO!";
		else
			count = std::to_string(i);

		Game.clear(sf::Color::Black);

		Game.draw(gameBoard);
		PointSetUp(Game,*snake_1, sf::Vector2f(0, 0), snakeColor1, player1Points);
		apple->render(Game);
		snake_1->render(Game);
		
		countDown.setString(count);
		countDown.setPosition(sf::Vector2f(Game.getSize().x / 2.f - countDown.getLocalBounds().width / 2.f, Game.getSize().y * .5f));
		Game.draw(countDown);
		Game.display();
		Sleep(1000);

	}

}

void GameBoard::startCountDown_2P(sf::RenderWindow& Game) {

	sf::Font font;
	if (!font.loadFromFile("../Fonts/Points_Font.ttf")) {
		std::cout << "ERROR FONT";
	}

	sf::Text countDown;
	countDown.setFont(font);
	countDown.setCharacterSize(400);
	countDown.setFillColor(sf::Color::Red);
	for (int i = 5; i > -1; i--) {

		sf::String count;
		if (i == 0)
			count = "GO!";
		else
			count = std::to_string(i);

		Game.clear(sf::Color::Black);

		Game.draw(gameBoard);
		PointSetUp(Game, *snake_1, sf::Vector2f(0, 0), snakeColor1, player1Points);
		PointSetUp(Game, *snake_2, sf::Vector2f(Game.getSize().x - player2Points.getLocalBounds().width, Game.getSize().y * .95), snakeColor2, player2Points);
		apple->render(Game);
		snake_1->render(Game);
		snake_2->render(Game);

		countDown.setString(count);
		countDown.setPosition(sf::Vector2f(Game.getSize().x / 2.f - countDown.getLocalBounds().width / 2.f, Game.getSize().y * .5f));
		Game.draw(countDown);
		Game.display();
		Sleep(1000);

	}
}

void GameBoard::gameDisplay_1P(sf::RenderWindow& Game) {

	startCountDown_1P(Game);

	while (Game.isOpen()) {

		sf::Event eventGame;
		while (Game.pollEvent(eventGame)) {

            snake_1->movementHandler_P1(eventGame);

			if (eventGame.type == sf::Event::KeyPressed && eventGame.key.code == sf::Keyboard::Escape)
				Game.close();			
		}
		drawBoard_1P(Game);
		foundApple(*apple, *snake_1, snakeColor1);
	}
}

void GameBoard::gameDisplay_2P(sf::RenderWindow& Game) {

	startCountDown_2P(Game);

	while (Game.isOpen()) {

		drawBoard_2P(Game);

		sf::Event eventGame;
		while (Game.pollEvent(eventGame)) {

			snake_1->movementHandler_P1(eventGame);
			snake_2->movementHandler_P2(eventGame);

			if (eventGame.type == sf::Event::KeyPressed && eventGame.key.code == sf::Keyboard::Escape)
				Game.close();
		}
		foundApple(*apple, *snake_1, snakeColor1);
		foundApple(*apple, *snake_2, snakeColor2);
	}
}

void GameBoard::BoardSetUp(sf::RenderWindow& Game) {
	grassTexture.loadFromFile("../Images/Grass.jpg");
	gameBoard.setTexture(grassTexture);

	float sizeX = .75*float(Game.getSize().x) / float(grassTexture.getSize().x);
	float sizeY = .75*float(Game.getSize().y) / float(grassTexture.getSize().y);

	gameBoard.setScale((sf::Vector2f(sizeX, sizeY)));
	gameBoard.setPosition(Game.getSize().x / 8.f, Game.getSize().y / 8.f + (gameBoard.getGlobalBounds().height/120));
}

void GameBoard::PointSetUp(sf::RenderWindow &Game,Snake &snake, sf::Vector2f pointsPosition, char snakeColor, sf::Text &pointsText) { //Setup Points(font,position,color...etc)
	pointsFont.loadFromFile("../Fonts/Points_Font.ttf");
	pointsText.setFont(pointsFont);
	snake.setPointsColor(snakeColor, pointsText);
	pointsText.setCharacterSize(100);
	pointsText.setString("Points " + std::to_string(snake.getPoints()));
	pointsText.setPosition(pointsPosition);
	Game.draw(pointsText);
}

void GameBoard::drawBoard_1P(sf::RenderWindow& Game) {

	Game.clear(sf::Color::Black);
	Game.draw(gameBoard);
	PointSetUp(Game, *snake_1, sf::Vector2f(0,0), snakeColor1, player1Points);


	apple->render(Game);

	if (!snake_1->collisionHandler(gameBoard)) {
		snake_1->render(Game);
		snake_1->updateSnakeBody();
	}

	if (snake_1->getGameOver() == true)
		Menu::drawTextMenu(Game, "GAME OVER", .05, 0);
	
	Game.display();
}

void GameBoard::drawBoard_2P(sf::RenderWindow& Game) {

	Game.clear(sf::Color::Black);
	Game.draw(gameBoard);
	PointSetUp(Game, *snake_1, sf::Vector2f(0, 0), snakeColor1, player1Points);
	PointSetUp(Game, *snake_2, sf::Vector2f(Game.getSize().x - player2Points.getLocalBounds().width, Game.getSize().y * .95), snakeColor2, player2Points);


	apple->render(Game);

	if (!snake_2->collisionHandler(gameBoard)) {
		snake_2->render(Game);
		snake_2->updateSnakeBody();
	}

	if (!snake_1->collisionHandler(gameBoard)) {
		snake_1->render(Game);
		snake_1->updateSnakeBody();
	}

	if (snake_2->getGameOver() == true && snake_1->getGameOver() == true)
		Menu::drawTextMenu(Game, "GAME OVER", .05 , 0);
	
	Game.display();
}
