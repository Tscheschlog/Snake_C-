#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <array>
#include <random>


// Apple Class
class Apple {
private:
    sf::Texture appleTexture;

public:
    sf::Sprite appleSprite;
    int xPos;
    int yPos;

    Apple(sf::Sprite Board, float gameBoardX, float gameBoardY);

    void newApple(sf::Sprite Board, float gameBoardX, float gameBoardY);

    void render(sf::RenderWindow&);

};