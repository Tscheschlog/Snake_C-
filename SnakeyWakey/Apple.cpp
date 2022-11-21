#include "Apple.h"
#include <iostream>

Apple::Apple(sf::Sprite Board, int gameBoardX, int gameBoardY) { //Setup Apple(size, texture, initial position...etc)

    // Generate Apple Inside GameBoard
    do {
        xPos = rand() % gameBoardX;
        yPos = rand() % gameBoardY;
    } while (!Board.getGlobalBounds().contains(xPos, yPos));

    if (!appleTexture.loadFromFile("../Images/Apple.png")) {
        std::cout << "UNABLE TO LOAD ASSET";
    }
    else {
        std::cout << "Asset Loaded";
    }
    appleSprite.setTexture(appleTexture);

    float sizeX = 40 / float(appleTexture.getSize().x);
    float sizeY = 40 / float(appleTexture.getSize().y);

    appleSprite.setScale((sf::Vector2f(sizeX, sizeY)));
    appleSprite.setPosition(xPos, yPos);
}

void Apple::newApple(sf::Sprite Board, int gameBoardX, int gameBoardY) {

    // Refer to constructor
    do {
        xPos = rand() % gameBoardX;
        yPos = rand() % gameBoardY;
    } while (!Board.getGlobalBounds().contains(xPos, yPos));
    appleSprite.setPosition(xPos, yPos);
}


void Apple::render(sf::RenderWindow& window) {

    window.draw(appleSprite);

}
