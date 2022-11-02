#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <array>
#include <random>


// Apple Class
class Apple {
private:
    sf::Sprite appleSprite;
    sf::Texture appleTexture;


public:
    int xPos;
    int yPos;

    Apple();

    void newApple();

    void render(sf::RenderWindow&);

};