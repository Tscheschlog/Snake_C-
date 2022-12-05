#pragma once
#include "Apple.h"
#include "Menu.h"
#include "Snake.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

class Options: public Apple, Snake, Menu {
	friend class GameBoard;
	friend class Apple;
private:
	segment player1head, player1body, player1tail; //Player 1 Segment for Visual Snake
	segment player2head, player2body, player2tail; //Player 2 Segments for Visual Snake
	sf::Texture arrowLeft, arrowRight;
	sf::RectangleShape playButton;
	sf::Sprite appleLeft, appleRight, snakeLeft1, snakeRight1, snakeLeft2, snakeRight2, speedLeft, speedRight; //Sprties with 1 in name is for Player 1 and with 2 in name is for Player 2
	static char appleColor, snakeColor1, snakeColor2;
	static int snakeSpeed;
public:
	Options(bool &);
	void OptionsWindow(sf::RenderWindow &Opt, bool &); //Makes it so it continues displaying Options Window
	void drawOptionsMenu(sf::RenderWindow& Opt); //Draws all the text and sprites in Options Menu
	void TextSetup(sf::RenderWindow& Opt, float postionX, float postionY, float size, sf::String stringText); //Setups up Text(size,color,postion..etc)
	void SnakeColorOption(sf::RenderWindow& Opt, float postionX, float postionY, sf::Vector2f optionSize, char& color, sf::Sprite snakeRight, sf::Sprite snakeLeft, segment& head, segment& body, segment& tail); //Setups up SnakeColorOption(text,arrows..etc)
	void ArrowSetup(sf::RenderWindow& Opt, sf::Sprite& optionSprite, sf::Vector2f(optionPostion), bool directionRight); //Setups the Arrows (size,postions,texture,direction..etc)
	bool ArrowClicked(sf::Sprite& optionClicked, sf::RenderWindow &Opt); //Returns bool whether arrow was clicked by user
	void changeSnakeColor(sf::RenderWindow& Opt, char& color, segment& head, segment& body, segment& tail, sf::Sprite& snakeRight, sf::Sprite& snakeLeft); //Changes the visual snake color for user and set the snakeColors
	void AppleColorOption(sf::RenderWindow& Opt, float postionX, float postionY, sf::Vector2f optionSize); //Setups the AppleColorOption(text,position,arrow..etc)
	void changeAppleColor(sf::RenderWindow& Opt); //Changes the visual apple for user and sets appleColor
	void snakeSpeedOption(sf::RenderWindow& Opt); //Setups the SnakeSpeedOption(text,postion,arrow..etc)
	void changeSnakeSpeed(sf::RenderWindow& Opt); //Changes the visual number for snakeSpeed and set value for snakeSpeed
};

