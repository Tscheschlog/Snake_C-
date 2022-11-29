#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "Snake.h"
#include "Apple.h"


class GameBoard
{
private:
	sf::RenderWindow* gameWindow;
	sf::Sprite gameBoard;
	sf::Texture grassTexture;
	sf::Font pointsFont;
	sf::Text pointsText;
	Snake* snake_1;
	Snake* snake_2;
	Apple* apple;
	float gameBoardWidth, gameBoardHeight;
	int points;
	void startCountDown_1P(sf::RenderWindow& Game);
	void startCountDown_2P(sf::RenderWindow& Game);
public:
	GameBoard(bool);
	void gameDisplay_1P(sf::RenderWindow& Game);
	void gameDisplay_2P(sf::RenderWindow& Game);
	void foundApple(Apple& apple, Snake& snake);
	void PointSetUp();
	void BoardSetUp(sf::RenderWindow& Game);
	void drawBoard_1P(sf::RenderWindow& Game);
	void drawBoard_2P(sf::RenderWindow& Game);
};


