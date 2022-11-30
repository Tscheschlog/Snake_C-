#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "Snake.h"
#include "Apple.h"
#include "Options.h"

class GameBoard:public Menu
{
private:
	sf::RenderWindow* gameWindow;
	sf::Sprite gameBoard;
	sf::Texture grassTexture;
	sf::Font pointsFont;
	Apple* apple;
	float gameBoardWidth, gameBoardHeight;
	void startCountDown_1P(sf::RenderWindow& Game);
	void startCountDown_2P(sf::RenderWindow& Game);
protected:
	Snake* snake_1;
	Snake* snake_2;
	char snakeColor1, snakeColor2;
	sf::Text player1Points, player2Points;
public:
	GameBoard() = default;
	GameBoard(bool);
	void gameDisplay_1P(sf::RenderWindow& Game);
	void gameDisplay_2P(sf::RenderWindow& Game);
	void foundApple(Apple& apple, Snake& snake, char &snakeColor);
	void PointSetUp(sf::RenderWindow &Game, Snake &snake, sf::Vector2f, char, sf::Text &);
	void BoardSetUp(sf::RenderWindow& Game);
	void drawBoard_1P(sf::RenderWindow& Game);
	void drawBoard_2P(sf::RenderWindow& Game);
};


