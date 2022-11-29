#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <array>
#include <random>


// Apple Class
class Apple {
    friend class Options;
private:
    sf::Texture appleTexture;
    char appleColor;

public:
    sf::Sprite appleSprite;
    int xPos;
    int yPos;
    Apple() = default;
    Apple(sf::Sprite Board, float gameBoardX,float gameBoardY);

    void newApple(sf::Sprite Board, float gameBoardX, float gameBoardY);

    void render(sf::RenderWindow&);

};