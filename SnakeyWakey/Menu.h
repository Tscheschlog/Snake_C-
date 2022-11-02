#pragma once
#include <string>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"


class Menu {
	sf::RectangleShape buttonSinglePlayer, buttonMultiPlayer;

public:
	bool singlePlayer, openGameWindow = true;
	Menu();
	void Continue(sf::RenderWindow& target);
	void drawTextMenu(sf::RenderWindow& target, sf::String title, int sizeFont, float heightFactor);
	void DrawMenu(sf::RenderWindow& target);
};



