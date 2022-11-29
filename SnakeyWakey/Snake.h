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
    inline bool operator==(segment&);
};

bool segment::operator==(segment& seg2) {

    if (xPos == seg2.xPos && yPos == seg2.yPos) {
        return true;
    }
    return false;
}

class Snake  {
    friend class Options;
private:
    char snakeColor;
    int speed;
    int res;
    int length;
    int points;
    int lastDirection;
    std::array<int, 2> lastPosition;
    std::vector<segment> body{};

    void initSnakeBody(sf::Sprite, float, float, bool);

    void updateShapePosition(segment& seg) {

        seg.shape.setPosition(seg.xPos, seg.yPos);

    }
    bool wallCollision(sf::Sprite);
    bool bodyCollision();

public:
    Snake(sf::Sprite, float, float, bool);

    bool collisionHandler(sf::Sprite);

    Snake() = default;

    segment getHeadPos() {
        return body[0];
    }

    void setLastPostion(int x, int y);

    void render(sf::RenderWindow&);

    void appleEaten();

    void updateSnakeTrail();

    void updateSnakeBody();

    void movementHandler_P1(sf::Event);
    void movementHandler_P2(sf::Event);

    int getPoints() {
        return points;
    }

    int getLastDirection() {
        return lastDirection;
    }

    void setLastDirection(int num) {
        lastDirection = num;
    }

    void setSnakeColor(sf::RectangleShape& rect);
};
