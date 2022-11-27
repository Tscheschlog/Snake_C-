#include "Apple.h"
#include <iostream>

Apple::Apple(sf::Sprite Board, float gameBoardX, float gameBoardY) { //Setup Apple(size, texture, initial position...etc) 

    if (!appleTexture.loadFromFile("../Images/Apple.png")) {
        std::cout << "UNABLE TO LOAD ASSET";
    }
    else {
        std::cout << "Asset Loaded";
    }
    appleSprite.setTexture(appleTexture);

    float sizeX = gameBoardX / 60 / float(appleTexture.getSize().x);
    float sizeY = gameBoardX / 60 / float(appleTexture.getSize().y);

    appleSprite.setScale((sf::Vector2f(sizeX, sizeY)));

    // Generate Apple Inside GameBoard
    xPos = (Board.getGlobalBounds().left + gameBoardX / 2 + 100);
    yPos = (Board.getGlobalBounds().top + gameBoardY / 2);


    appleSprite.setPosition(xPos, yPos);
}

void Apple::newApple(sf::Sprite Board, float gameBoardX, float gameBoardY) {

    // Refer to constructor
    do {
        xPos = Board.getGlobalBounds().left + appleSprite.getScale().x*appleTexture.getSize().x * (rand() % 59);
        yPos = Board.getGlobalBounds().top + appleSprite.getScale().x*appleTexture.getSize().y * (rand() % 59);
    } while (!Board.getGlobalBounds().contains(xPos, yPos));

    appleSprite.setPosition(xPos, yPos);
}


void Apple::render(sf::RenderWindow& window) {

    window.draw(appleSprite);
}
