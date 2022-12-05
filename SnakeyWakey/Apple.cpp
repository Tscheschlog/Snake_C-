#include "Apple.h"
#include "Options.h"
#include <iostream>

Apple::Apple(sf::Sprite Board, float gameBoardX, float gameBoardY) { //Setup Apple(size, texture, initial position...etc)
    appleColor = Options::appleColor;

    switch (appleColor) {
        case 'R': {
            appleTexture.loadFromFile("../Images/RedApple.png");
            appleSprite.setTexture(appleTexture);
            break;
        }
        case 'G': {
            appleTexture.loadFromFile("../Images/GreenApple.png");
            appleSprite.setTexture(appleTexture);
            break;
        }
        case 'B': {
            appleTexture.loadFromFile("../Images/BlueApple.png");
            appleSprite.setTexture(appleTexture);
            break;
        }
        case 'Y': {
            appleTexture.loadFromFile("../Images/YellowApple.png");
            appleSprite.setTexture(appleTexture);
        }
    }

   // Set size of the apple sprite
    float sizeX = gameBoardX / 60 / float(appleSprite.getLocalBounds().width);
    float sizeY = gameBoardX / 60 / float(appleSprite.getLocalBounds().height);
    appleSprite.setScale((sf::Vector2f(sizeX, sizeY)));

    // Generate Apple Inside GameBoard
    xPos = (Board.getGlobalBounds().left + gameBoardX / 2);
    yPos = (Board.getGlobalBounds().top + gameBoardY / 2);


    appleSprite.setPosition(xPos, yPos);
}


void Apple::newApple(sf::Sprite Board, float gameBoardX, float gameBoardY) {

    // Refer to constructor
    do {
        xPos = Board.getGlobalBounds().left + appleSprite.getScale().x*appleSprite.getLocalBounds().width * (rand() % 60);
        yPos = Board.getGlobalBounds().top + appleSprite.getScale().y*appleSprite.getLocalBounds().height * (rand() % 30);
    } while (!Board.getGlobalBounds().contains(xPos, yPos));


    appleSprite.setPosition(xPos, yPos);
}

void Apple::render(sf::RenderWindow& window) {

    /* ---> Apple outline in case of misalignment <---
    * 
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::Black);
    rect.setSize(sf::Vector2f(appleTexture.getSize()));
    rect.setScale(sf::Vector2f(appleSprite.getScale()));
    rect.setPosition(sf::Vector2f(appleSprite.getPosition()));
    window.draw(rect);
    *
    */

    window.draw(appleSprite);
}
