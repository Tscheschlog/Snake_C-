#include "Menu.h"
#include "SoundFX.h"
#include <string>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"


Menu::Menu(int fps) { //Setup Menu window  
	sf::RenderWindow menuWindow(sf::VideoMode(), "Snake!", sf::Style::Fullscreen);
	menuWindow.setFramerateLimit(fps);
	Continue(menuWindow);
}


void Menu::highlightButton(sf::RectangleShape& Rect, sf::RenderWindow& target) {

	if (Rect.getGlobalBounds().contains(sf::Mouse::getPosition(target).x, sf::Mouse::getPosition(target).y)) {
		Rect.setFillColor(sf::Color::White);
	}
	else {
		Rect.setFillColor(sf::Color::Transparent);
	}

}

bool Menu::openGameWindow = true;
bool Menu::singlePlayer = true;

void Menu::Continue(sf::RenderWindow& target) {
	sound.playMusic("../Music/music.ogg");
	while (target.isOpen()) {

		sf::Event eventMenu;
		while (target.pollEvent(eventMenu)) {
			if (eventMenu.type == sf::Event::Closed) {
				openGameWindow = false;
				target.close();
			}
			else if (eventMenu.type == sf::Event::KeyPressed && eventMenu.key.code == sf::Keyboard::Escape) {
				openGameWindow = false;
				target.close();
			}
			else if (eventMenu.type == sf::Event::MouseButtonPressed && eventMenu.mouseButton.button == sf::Mouse::Left) { //Checks if users clicks on button

				if (buttonSinglePlayer.getGlobalBounds().contains(sf::Mouse::getPosition(target).x, sf::Mouse::getPosition(target).y)) {
					singlePlayer = true; //Single Player Button pressed
					target.close();
				}
				else if (buttonMultiPlayer.getGlobalBounds().contains(sf::Mouse::getPosition(target).x, sf::Mouse::getPosition(target).y)) {
					singlePlayer = false; //MultiPlayer Button pressed
					target.close();
				}
			}
		}
		DrawMenu(target);
	}
}

void Menu::drawTextMenu(sf::RenderWindow& target, sf::String title, int sizeFont, float heightFactor) { //Setup Text(font, color, size, position...etc)
	sf::Font menuFont;
	if (!menuFont.loadFromFile("../Fonts/Menu_Font.ttf")) {
		std::cout << "UNABLE TO LOAD";
	}
	sf::Text menuText;
	menuText.setFont(menuFont);
	menuText.setLetterSpacing(1);
	menuText.setOutlineColor(sf::Color::White);
	menuText.setOutlineThickness(1);
	menuText.setCharacterSize(sizeFont);
	menuText.setFillColor(sf::Color::Red);
	menuText.setString(title);
	menuText.setPosition(target.getSize().x / 2.f - menuText.getLocalBounds().width/2.f, target.getSize().y * heightFactor);

	target.draw(menuText);
}

void Menu::MenuButtonSetup(sf::RectangleShape &Rect, sf::RenderWindow &target, sf::Vector2f position) { //Setup Buttons Setting(Color,Position,Size..etc)
	highlightButton(Rect, target);
	Rect.setSize(sf::Vector2f(target.getSize().x * .40, target.getSize().y * .15));
	Rect.setOutlineThickness(2);
	Rect.setOutlineColor(sf::Color::Red);
	Rect.setPosition(position);
}

void Menu::DrawMenu(sf::RenderWindow& target) { //Draw Menu Text, Buttons
	target.clear(sf::Color::Black);
	drawTextMenu(target, "SNAKE", 250, 0);

	MenuButtonSetup(buttonSinglePlayer, target, sf::Vector2f(target.getSize().x * 3.625 / 12.0, target.getSize().y * 7.10 / 12.0));
	target.draw(buttonSinglePlayer);
	drawTextMenu(target, "SINGLE", 125, 7.0 / 12.0);

	MenuButtonSetup(buttonMultiPlayer, target, sf::Vector2f(target.getSize().x * 3.625 / 12.0, target.getSize().y * 9.10 / 12.0));
	target.draw(buttonMultiPlayer);
	drawTextMenu(target, "MULTIPLAYER", 125, 9.0 / 12.0);


	target.display();
}




