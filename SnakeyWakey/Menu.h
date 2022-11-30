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
	static bool openGameWindow, singlePlayer;
	Menu(int fps);
	Menu() {

	};
	void MenuButtonSetup(sf::RectangleShape& Rect, sf::RenderWindow& target, sf::Vector2f position);
	void highlightButton(sf::RectangleShape& Rect, sf::RenderWindow& target);
	void Continue(sf::RenderWindow& target);
	void drawTextMenu(sf::RenderWindow& target, sf::String title, int sizeFont, float heightFactor);
	void DrawMenu(sf::RenderWindow& target);
};



