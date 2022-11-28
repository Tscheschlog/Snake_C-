#pragma once
#include "Apple.h"
#include "Menu.h"
#include "Snake.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

class Options: public Apple, Snake, Menu{
	friend class Snake;
	friend class Apple;
private:
	sf::Texture arrowLeft, arrowRight;
	sf::RectangleShape playButton;
	sf::Sprite appleLeft, appleRight, snakeLeft, snakeRight, speedLeft, speedRight;
	segment head, body, tail;
	static char appleColor, snakeColor;
	static int snakeSpeed;
public:
	Options();
	void OptionsWindow(sf::RenderWindow &Opt); //Makes it so continue displaying Options Window
	void drawOptionsMenu(sf::RenderWindow& Opt); //Draws all the text and sprites in Options Menu
	void TextSetup(sf::RenderWindow& Opt, float postionX, float postionY, float size, sf::String stringText); //Setups up text size,color,postion..etc
	void SnakeColorOption(sf::RenderWindow& Opt, float postionX, float postionY, sf::Vector2f optionSize); //Setups up snake color option text,arrows..etc
	void ArrowSetup(sf::RenderWindow& Opt, sf::Sprite& optionSprite, sf::Vector2f(optionPostion), bool directionRight); //Setups the arrows size,postions,texture..etc
	bool ArrowClicked(sf::Sprite& optionClicked, sf::RenderWindow &Opt); //Returns bool whether arrow was clicked by user
	void changeSnakeColor(sf::RenderWindow &Opt); //Changes the visual snake color for user 
	void AppleColorOption(sf::RenderWindow& Opt, float postionX, float postionY, sf::Vector2f optionSize); //Setups the apple color option text,position,arrow..etc
	void changeAppleColor(sf::RenderWindow& Opt); //Changes the visual apple for user
	void snakeSpeedOption(sf::RenderWindow& Opt);
	void changeSnakeSpeed(sf::RenderWindow& Opt);
};

