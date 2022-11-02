#include "Apple.h"
#include <iostream>

Apple::Apple() {

    // Generate 0-39 --> x20 --> 0, 20, 40, 60, ..., 780
    xPos = rand() % 39 * 20;
    yPos = rand() % 39 * 20;

    if (!appleTexture.loadFromFile("C:/Users/12676/source/repos/SnakeC++/Snake-Game/Images/Apple.png")) {
        std::cout << "UNABLE TO LOAD ASSET";
    }
    else {
        std::cout << "Asset Loaded";
    }
    appleSprite.setTexture(appleTexture);

    float sizeX = 20 / float(appleTexture.getSize().x);
    float sizeY = 20 / float(appleTexture.getSize().y);

    appleSprite.setScale((sf::Vector2f(sizeX, sizeY)));
    appleSprite.setPosition(xPos, yPos);
}

void Apple::newApple() {

    // Refer to constructor
    xPos = rand() % 10 * 20;
    yPos = rand() % 10 * 20;
    appleSprite.setPosition(xPos, yPos);
}

void Apple::render(sf::RenderWindow& window) {

    window.draw(appleSprite);

}
