#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "Snake.h"
#include "Apple.h"
#include "Options.h"


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
	char snakeColor1, snakeColor2;
	float gameBoardWidth, gameBoardHeight;
	void startCountDown_1P(sf::RenderWindow& Game, Snake &snake);
	void startCountDown_2P(sf::RenderWindow& Game, Snake &snake);
public:
	GameBoard(bool);
	void gameDisplay_1P(sf::RenderWindow& Game);
	void gameDisplay_2P(sf::RenderWindow& Game);
	void foundApple(Apple& apple, Snake& snake, char &snakeColor);
	void PointSetUp();
	void BoardSetUp(sf::RenderWindow& Game);
	void drawBoard_1P(sf::RenderWindow& Game);
	void drawBoard_2P(sf::RenderWindow& Game);
};


