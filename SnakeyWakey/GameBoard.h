#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "Snake.h"
#include "Apple.h"


class SnakeGameBoard
{
private:
	sf::RenderWindow* gameWindow;
	sf::Sprite gameBoard;
	sf::Texture grassTexture;
	Snake* snake;
	Apple* apple;
	unsigned int gameBoardWidth, gameBoardHeight;
public:
	SnakeGameBoard();
	void gameDisplay(sf::RenderWindow& Game);
	void BoardSetUp(sf::RenderWindow& Game);
	void AppleSetUp();
	void drawBoard(sf::RenderWindow& Game);
	void getAppleSpawn();
};


