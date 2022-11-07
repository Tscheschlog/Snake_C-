#include "Menu.h"
#include <string>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"


Menu::Menu() {
	sf::RenderWindow menuWindow(sf::VideoMode(), "Snake!", sf::Style::Fullscreen);
	menuWindow.setFramerateLimit(60);
	buttonSinglePlayer.setSize(sf::Vector2f(385.f, 200.f));
	buttonSinglePlayer.setFillColor(sf::Color::Transparent);
	buttonMultiPlayer.setSize(sf::Vector2f(750.f, 175.f));
	buttonMultiPlayer.setFillColor(sf::Color::Transparent);
	Continue(menuWindow);
}

void Menu::Continue(sf::RenderWindow& target) {
	while (target.isOpen()) {
		sf::Event eventMenu;
		while (target.pollEvent(eventMenu)) {
			if (eventMenu.type == sf::Event::Closed) {
				target.close();
				openGameWindow = false;
			}
			else if (eventMenu.type == sf::Event::KeyPressed && eventMenu.key.code == sf::Keyboard::Escape) {
				target.close();
				openGameWindow = false;
			}
			else if (eventMenu.type == sf::Event::MouseButtonPressed && eventMenu.mouseButton.button == sf::Mouse::Left) {

				if (buttonSinglePlayer.getGlobalBounds().contains(sf::Mouse::getPosition(target).x, sf::Mouse::getPosition(target).y)) {
					target.close();
					singlePlayer = true;
				}
				else if (buttonMultiPlayer.getGlobalBounds().contains(sf::Mouse::getPosition(target).x, sf::Mouse::getPosition(target).y)) {
					target.close();
					singlePlayer = false;
				}
			}
		}
		DrawMenu(target);
	}
}

void Menu::drawTextMenu(sf::RenderWindow& target, sf::String title, int sizeFont, float heightFactor) {
	sf::Font menuFont;
	if (!menuFont.loadFromFile("../Fonts/Menu_Font.ttf")) {
		std::cout << "UNABLE TO LOAD";
	}

	sf::Text menuText;
	menuText.setFont(menuFont);
	menuText.setCharacterSize(sizeFont);
	menuText.setFillColor(sf::Color::Red);
	menuText.setString(title);
	menuText.setPosition(target.getSize().x / 2.f - menuText.getLocalBounds().width/2.f, target.getSize().y * heightFactor);

	target.draw(menuText);
}

void Menu::DrawMenu(sf::RenderWindow& target) {
	target.clear(sf::Color::Black);
	drawTextMenu(target, "SNAKE", 250, 0);


	drawTextMenu(target, "SINGLE", 125, 7.0/12.0);
	buttonSinglePlayer.setPosition(target.getSize().x * 3.625 / 12.0, target.getSize().y * 7.10 / 12.0);
	buttonSinglePlayer.setSize(sf::Vector2f(target.getSize().x * .40, target.getSize().y * .15));
	buttonSinglePlayer.setOutlineThickness(2);
	buttonSinglePlayer.setOutlineColor(sf::Color::Red);

	target.draw(buttonSinglePlayer);

	drawTextMenu(target, "MULTIPLAYER", 125, 9.0 / 12.0);
	buttonMultiPlayer.setPosition(target.getSize().x * 3.625 / 12.0, target.getSize().y * 9.10 / 12.0);
	buttonMultiPlayer.setSize(sf::Vector2f(target.getSize().x * .40, target.getSize().y * .15));
	buttonMultiPlayer.setOutlineThickness(2);
	buttonMultiPlayer.setOutlineColor(sf::Color::Red);
	target.draw(buttonMultiPlayer);

	target.display();
}




