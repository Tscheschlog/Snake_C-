#pragma once
#include "GameBoard.h"
#include "Menu.h"

class Snake;

class GameOver:public GameBoard, Menu
{
private:
public:
	GameOver(int player_1Points, int player_2Points = 0);
	void gameOverWindow(sf::RenderWindow& gameOver, int player_1Points, int player_2Points = 0);
	void drawGameOver(sf::RenderWindow& gameOver, int player_1Points, int player_2Points = 0);
};

