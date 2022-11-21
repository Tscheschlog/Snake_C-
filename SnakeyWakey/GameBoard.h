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
	Snake* snake;
	Apple* apple;
	unsigned int gameBoardWidth, gameBoardHeight, points;
public:
	GameBoard();
	void gameDisplay(sf::RenderWindow& Game);
	void foundApple(Apple& apple, Snake& snake);
	void PointSetUp();
	void BoardSetUp(sf::RenderWindow& Game);
	void drawBoard(sf::RenderWindow& Game);
};


