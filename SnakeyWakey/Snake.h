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
    int lastDirection;
    std::array<int, 2> lastPosition;
    std::vector<segment> body{};

    void initSnakeBody(sf::Sprite board, float gameBoardX, float gameBoardY);

    void updateShapePosition(segment& seg) {

        seg.shape.setPosition(seg.xPos, seg.yPos);

    }
    bool wallCollision(sf::Sprite);
    bool bodyCollision();
public:
    Snake(sf::Sprite Board, float gameBoardX, float gameBoardY);

    bool collisionHandler(sf::Sprite);

    Snake() {

    };

    segment getHeadPos() {
        return body[0];
    }

    void setLastPostion(int x, int y);

    void render(sf::RenderWindow&);

    void appleEaten(int &points);

    void updateSnakeTrail();

    void updateSnakeBody();

    void movementHandler(sf::Event event);

    int getLastDirection() {
        return lastDirection;
    }

    void setLastDirection(int num) {
        lastDirection = num;
    }

    void setSnakeColor(sf::RectangleShape& rect);
};
