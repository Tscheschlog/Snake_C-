#include "GameOver.h"
#include "Snake.h"
#include "GameBoard.h"
#include "Menu.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

GameOver::GameOver(int player_1Points, int player_2Points) {
	sf::RenderWindow gameOver(sf::VideoMode(850, 650), "Game Over!");
	gameOverWindow(gameOver, player_1Points, player_2Points);
}

void GameOver::gameOverWindow(sf::RenderWindow& gameOver, int player_1Points, int player_2Points) {
	while (gameOver.isOpen()) {
		sf::Event gameOverEvent;
		while (gameOver.pollEvent(gameOverEvent)) {
			if (gameOverEvent.type == sf::Event::KeyPressed && gameOverEvent.key.code == sf::Keyboard::Escape) {
				gameOver.close();
			}
			else if (gameOverEvent.type == sf::Event::Closed) {
				gameOver.close();
			}
		}
		drawGameOver(gameOver, player_1Points, player_2Points);
	}
}

void GameOver::drawGameOver(sf::RenderWindow& gameOver, int player_1Points, int player_2Points) {
	gameOver.clear(sf::Color::Black);

	drawTextMenu(gameOver, "Game Over", 100, 0);


	if (!Menu::singlePlayer) {
		PointSetUp(gameOver, *snake_1, sf::Vector2f(gameOver.getSize().x * .50, gameOver.getSize().y * .50), snakeColor1, player1Points, player_1Points);
		PointSetUp(gameOver, *snake_2, sf::Vector2f(gameOver.getSize().x * .50, gameOver.getSize().y * .55), snakeColor2, player2Points, player_2Points);
	}
	else
		PointSetUp(gameOver, *snake_1, sf::Vector2f(gameOver.getSize().x * .50, gameOver.getSize().y * .50), snakeColor1, player1Points, player_1Points);

	gameOver.display();
}