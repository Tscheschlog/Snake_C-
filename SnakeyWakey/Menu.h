#pragma once
#include <string>
#include <iostream>
#include "SoundFX.h"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"



class Menu {
	sf::RectangleShape buttonSinglePlayer, buttonMultiPlayer;
	Sound sound;
public:
	static bool singlePlayer;
	Menu(bool &);
	Menu() = default;
	void MenuButtonSetup(sf::RectangleShape& Rect, sf::RenderWindow& target, sf::Vector2f position, bool);
	void highlightButton(sf::RectangleShape& Rect, sf::RenderWindow& target);
	void Continue(sf::RenderWindow& target, bool &);
	void drawTextMenu(sf::RenderWindow& target, sf::String title, float sizeFont, float heightFactor);
	void DrawMenu(sf::RenderWindow& target);
};



