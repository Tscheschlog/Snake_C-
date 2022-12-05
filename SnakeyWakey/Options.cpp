#include "Options.h"
#include <string>
#include <iostream>

char Options::appleColor = 'R';
char Options::snakeColor1 = 'W';
char Options::snakeColor2 = 'W';
int Options::snakeSpeed = 1;

Options::Options(bool &continueGame) {
	sf::RenderWindow OptionsMenu(sf::VideoMode(), "Options!", sf::Style::Fullscreen);
	OptionsMenu.setFramerateLimit(8);
	appleColor = 'R'; 
	snakeColor1 = 'W';
	snakeColor2 = 'W';
	snakeSpeed = 1;	
	arrowLeft.loadFromFile("../Images/LeftArrow.png");
	arrowRight.loadFromFile("../Images/RightArrow.png");
	Apple::appleTexture.loadFromFile("../Images/RedApple.png");
	Apple::appleSprite.setTexture(Apple::appleTexture);
	OptionsWindow(OptionsMenu, continueGame);
}

void Options::OptionsWindow(sf::RenderWindow& Opt, bool &continueGame) {
	while (Opt.isOpen()) {
		sf::Event optEvent;
		while (Opt.pollEvent(optEvent)) {
			if (optEvent.type == sf::Event::KeyPressed && optEvent.key.code == sf::Keyboard::Escape) {
				continueGame = false;
				Opt.close();
			}
			else if (optEvent.type == sf::Event::MouseButtonPressed && optEvent.mouseButton.button == sf::Mouse::Left) {
				if (playButton.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
					continueGame = true;
					Opt.close();
				}
			}
		}
		drawOptionsMenu(Opt);
	}
}

void Options::TextSetup(sf::RenderWindow& Opt, float postionX, float postionY, float sizeText, sf::String stringText) {
	sf::Font OptionsFont;
	if (!OptionsFont.loadFromFile("../Fonts/Points_Font.ttf")) {
		std::cout << "UNABLE TO LOAD";
	}
	sf::Text OptionsText;
	OptionsText.setFont(OptionsFont);
	OptionsText.setFillColor(sf::Color::Red);
	OptionsText.setCharacterSize(Opt.getSize().x * sizeText);
	OptionsText.setString(stringText);
	OptionsText.setPosition(sf::Vector2f((postionX - OptionsText.getLocalBounds().width / 2.f), postionY*0.90f));

	Opt.draw(OptionsText);
}

bool Options::ArrowClicked(sf::Sprite& optionClicked, sf::RenderWindow &Opt) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (optionClicked.getGlobalBounds().contains(sf::Mouse::getPosition(Opt).x, sf::Mouse::getPosition(Opt).y)) {
			return true;
		}
	}		
	else false;
}

void Options::ArrowSetup(sf::RenderWindow &Opt, sf::Sprite &optionSprite, sf::Vector2f(optionPostion), bool directionRight) {
	if (directionRight) 
		optionSprite.setTexture(arrowRight);
	else
		optionSprite.setTexture(arrowLeft);
	optionSprite.setPosition(optionPostion);
	optionSprite.setScale(sf::Vector2f(.15f, .15f));
	Opt.draw(optionSprite);
}

void Options::SnakeColorOption(sf::RenderWindow& Opt, float postionX, float postionY, sf::Vector2f optionSize, char &color, sf::Sprite snakeRight, sf::Sprite snakeLeft, segment& head, segment& body, segment& tail) {

	ArrowSetup(Opt, snakeRight, sf::Vector2f(postionX + 145.f, postionY - 10.f), true);
	ArrowSetup(Opt, snakeLeft, sf::Vector2f(postionX - 75.f, postionY - 10.f), false);

	head.shape.setPosition(sf::Vector2f(postionX  , postionY));
	body.shape.setPosition(sf::Vector2f(postionX + 40.f, postionY));
	tail.shape.setPosition(sf::Vector2f(postionX + 70.f, postionY));

	head.shape.setSize(optionSize);
	body.shape.setSize(optionSize);
	tail.shape.setSize(optionSize);
	
	changeSnakeColor(Opt, color, head, body,tail, snakeRight, snakeLeft);

	Opt.draw(head.shape);
	Opt.draw(body.shape);
	Opt.draw(tail.shape);
}

void Options::changeSnakeColor(sf::RenderWindow &Opt, char &color, segment &head, segment &body, segment &tail, sf::Sprite &snakeRight, sf::Sprite &snakeLeft) {
	if (ArrowClicked(snakeRight, Opt)) { //Right Snake Arrow clicked
		switch (color) {
		case 'W': {
			color = 'G';
			head.shape.setFillColor(sf::Color::Green);
			body.shape.setFillColor(sf::Color::Green);
			tail.shape.setFillColor(sf::Color::Green);
			break;
		}
		case 'G': {
			color = 'R';
			head.shape.setFillColor(sf::Color::Red);
			body.shape.setFillColor(sf::Color::Red);
			tail.shape.setFillColor(sf::Color::Red);
			break;
		}
		case 'R':{
			color = 'B';
			head.shape.setFillColor(sf::Color::Blue);
			body.shape.setFillColor(sf::Color::Blue);
			tail.shape.setFillColor(sf::Color::Blue);
			break;
		}
		case 'B': {
			color = 'Y';
			head.shape.setFillColor(sf::Color::Yellow);
			body.shape.setFillColor(sf::Color::Yellow);
			tail.shape.setFillColor(sf::Color::Yellow);
			break;
		}
		case 'Y': {
			color = 'M';
			head.shape.setFillColor(sf::Color::Magenta);
			body.shape.setFillColor(sf::Color::Magenta);
			tail.shape.setFillColor(sf::Color::Magenta);
			break;
		}
		case 'M': {
			color = 'W';
			head.shape.setFillColor(sf::Color::White);
			body.shape.setFillColor(sf::Color::White);
			tail.shape.setFillColor(sf::Color::White);
		}
		}
	}
	else if (ArrowClicked(snakeLeft,Opt)) { //Left Snake Arrow Clicked
		switch (color) {
		case 'G': {
			color = 'W';
			head.shape.setFillColor(sf::Color::White);
			body.shape.setFillColor(sf::Color::White);
			tail.shape.setFillColor(sf::Color::White);
			break;
		}
		case 'W': {
			color = 'M';
			head.shape.setFillColor(sf::Color::Magenta);
			body.shape.setFillColor(sf::Color::Magenta);
			tail.shape.setFillColor(sf::Color::Magenta);
			break;
		}
		case 'R': {
			color = 'G';
			head.shape.setFillColor(sf::Color::Green);
			body.shape.setFillColor(sf::Color::Green);
			tail.shape.setFillColor(sf::Color::Green);
			break;
		}
		case 'B': {
			color = 'R';
			head.shape.setFillColor(sf::Color::Red);
			body.shape.setFillColor(sf::Color::Red);
			tail.shape.setFillColor(sf::Color::Red);
			break;
		}
		case 'Y': {
			color = 'B';
			head.shape.setFillColor(sf::Color::Blue);
			body.shape.setFillColor(sf::Color::Blue);
			tail.shape.setFillColor(sf::Color::Blue);
			break;
		}
		case 'M': {
			color = 'Y';
			head.shape.setFillColor(sf::Color::Yellow);
			body.shape.setFillColor(sf::Color::Yellow);
			tail.shape.setFillColor(sf::Color::Yellow);
		}
		}
	}
}

void Options::AppleColorOption(sf::RenderWindow& Opt, float postionX, float postionY, sf::Vector2f optionSize) {
	ArrowSetup(Opt, appleRight, sf::Vector2f(postionX + 135.f, postionY + 40.f), true);
	ArrowSetup(Opt, appleLeft, sf::Vector2f(postionX - 70.f, postionY + 40.f), false);

	Apple::appleSprite.setPosition(sf::Vector2f(postionX, postionY));
	Apple::appleSprite.setScale(optionSize);

	changeAppleColor(Opt);

	Opt.draw(Apple::appleSprite);
}

void Options::changeAppleColor(sf::RenderWindow& Opt) {
	if (ArrowClicked(appleRight, Opt)) { //Right Apple Arrow Clicked
		switch (appleColor) {
			case 'R': {
				appleColor = 'G';
				Apple::appleTexture.loadFromFile("../Images/GreenApple.png");
				Apple::appleSprite.setTexture(Apple::appleTexture);
				break;
			}
			case 'G': {
				appleColor = 'B';
				Apple::appleTexture.loadFromFile("../Images/BlueApple.png");
				Apple::appleSprite.setTexture(Apple::appleTexture);
				break;
			}
			case 'B': {
				appleColor = 'Y';
				Apple::appleTexture.loadFromFile("../Images/YellowApple.png");
				Apple::appleSprite.setTexture(Apple::appleTexture);
				break;
			}
			case 'Y': {
				appleColor = 'R';
				Apple::appleTexture.loadFromFile("../Images/RedApple.png");
				Apple::appleSprite.setTexture(Apple::appleTexture);
			}
		}
	}
	else if (ArrowClicked(appleLeft, Opt)) { //Left Apple Arrow Clicked
		switch (appleColor) {
			case 'R': {
				appleColor = 'Y';
				Apple::appleTexture.loadFromFile("../Images/YellowApple.png");
				Apple::appleSprite.setTexture(Apple::appleTexture);
				break;
			}
			case 'G': {
				appleColor = 'R';
				Apple::appleTexture.loadFromFile("../Images/RedApple.png");
				Apple::appleSprite.setTexture(Apple::appleTexture);
				break;
			}
			case 'B': {
				appleColor = 'G';
				Apple::appleTexture.loadFromFile("../Images/GreenApple.png");
				appleSprite.setTexture(Apple::appleTexture);
				break;
			}
			case 'Y': {
				appleColor = 'B';
				Apple::appleTexture.loadFromFile("../Images/BlueApple.png");
				Apple::appleSprite.setTexture(Apple::appleTexture);
			}
		}
	}

}

void Options::snakeSpeedOption(sf::RenderWindow& Opt) {
	ArrowSetup(Opt, speedRight, sf::Vector2f(Opt.getSize().x * .52, Opt.getSize().y * .535), true);
	ArrowSetup(Opt, speedLeft, sf::Vector2f(Opt.getSize().x * .4575, Opt.getSize().y * .535), false);

	changeSnakeSpeed(Opt);
}

void Options::changeSnakeSpeed(sf::RenderWindow& Opt) {
	if (ArrowClicked(speedRight, Opt)) {
		if (snakeSpeed < 5)
			snakeSpeed++;
	}
	else if (ArrowClicked(speedLeft, Opt)) {
		if (snakeSpeed > 1) {
			snakeSpeed--;
		}
	}
}


void Options::drawOptionsMenu(sf::RenderWindow& Opt) {
	Opt.clear(sf::Color::Black);

	if (Menu::singlePlayer == true) { //Executes SinglePlayerOptionsMenu if User in previous Menu Window pressed singlePlayer
		TextSetup(Opt, Opt.getSize().x / 2.f, 0, 0.05, "Options Menu");

		TextSetup(Opt, Opt.getSize().x * .25f, Opt.getSize().y * .25f, 0.05, "Snake Color");
		SnakeColorOption(Opt, Opt.getSize().x * .23f, Opt.getSize().y * .35f, sf::Vector2f(50.f, 30.f), snakeColor1, snakeRight1, snakeLeft1, player1head, player1body, player1tail);

		TextSetup(Opt, Opt.getSize().x * .75f, Opt.getSize().y * .25f, 0.05, "Apple Color");
		AppleColorOption(Opt, Opt.getSize().x * .735f, Opt.getSize().y * .335f, sf::Vector2f(.25f, .25f));

		TextSetup(Opt, Opt.getSize().x * .50f, Opt.getSize().y * .45f, 0.05, "Snake Speed");
		TextSetup(Opt, Opt.getSize().x * .50f, Opt.getSize().y * .55f, 0.05, std::to_string(snakeSpeed));
		snakeSpeedOption(Opt);

		MenuButtonSetup(playButton, Opt, sf::Vector2f(Opt.getSize().x * 3.625 / 12.0, Opt.getSize().y * 9.10 / 12.0), true);
		Opt.draw(playButton);
		TextSetup(Opt, Opt.getSize().x * .50f, Opt.getSize().y * .80f, 0.09, "Play");
		highlightButton(playButton, Opt);
	}
	else { //Executes MultiPlayerOptionsMenu if User pressed MultiPlayer
		TextSetup(Opt, Opt.getSize().x / 2.f, 0, 0.05, "Options Menu");
		
		TextSetup(Opt, Opt.getSize().x * .25f, Opt.getSize().y * .25f, 0.05, "Player 1");
		SnakeColorOption(Opt, Opt.getSize().x * .23f, Opt.getSize().y * .35f, sf::Vector2f(50.f, 30.f), snakeColor1, snakeRight1, snakeLeft1, player1head, player1body, player1tail);

		TextSetup(Opt, Opt.getSize().x * .75f, Opt.getSize().y * .25f, 0.05, "Player 2");
		SnakeColorOption(Opt, Opt.getSize().x * .735f, Opt.getSize().y * .35f, sf::Vector2f(50.f, 30.f), snakeColor2, snakeRight2, snakeLeft2, player2head, player2body, player2tail);

		TextSetup(Opt, Opt.getSize().x * .50f, Opt.getSize().y * .50f, 0.05, "Apple Color");
		AppleColorOption(Opt, Opt.getSize().x * .485f, Opt.getSize().y * .55f , sf::Vector2f(.25f, .25f));

		MenuButtonSetup(playButton, Opt, sf::Vector2f(Opt.getSize().x * 3.625 / 12.0, Opt.getSize().y * 9.10 / 12.0), true);
		Opt.draw(playButton);
		TextSetup(Opt, Opt.getSize().x * .50f, Opt.getSize().y * .80f, 0.09, "Play");
		highlightButton(playButton, Opt);
	}

	/*
	
	---Set size relative to apple texture selected---
	
	float sizeX = Opt.getSize().x / 20 / float(appleSprite.getLocalBounds().width);
	float sizeY = Opt.getSize().x / 20 / float(appleSprite.getLocalBounds().height);
	Apple::appleSprite.setScale((sf::Vector2f(sizeX, sizeY)));
	
	*/

	Opt.display();
}
