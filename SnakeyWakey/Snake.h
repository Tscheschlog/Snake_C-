#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <array>
#include <random>
#include "Snake.h"


class GameBoard;

struct segment {
    sf::RectangleShape shape;
    int xPos;
    int yPos;
};

class Snake  {

private:
    int speed;
    int res;
    int length;
    int lastDirection;
    std::array<int, 2> lastPosition;
    std::vector<segment> body{};

    void initSnakeBody(int gameBoardX, int gameBoardY);

    void updateShapePosition(segment& seg) {

        seg.shape.setPosition(seg.xPos, seg.yPos);

    }

public:
    Snake(int gameBoardX, int gameBoardY);

    segment getHeadPos() {
        return body[0];
    }

    void setLastPostion(int x, int y);

    void render(sf::RenderWindow&);

    void appleEaten(unsigned int &points);

    void updateSnakeTrail();

    void updateSnakeBody();

    void movementHandler(sf::Event event);

    int getLastDirection() {
        return lastDirection;
    }

    void setLastDirection(int num) {
        lastDirection = num;
    }
};
