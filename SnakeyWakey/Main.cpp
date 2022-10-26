#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <array>
#include <random>

// Init the window
sf::RenderWindow window(sf::VideoMode(800, 800), "SnakeyWakey");

// Apple Class
class Apple {
private:
    sf::RectangleShape shape;


public:
    int xPos;
    int yPos;


    Apple() {

        // Generate 0-39 --> x20 --> 0, 20, 40, 60, ..., 780
        xPos = rand() % 39 * 20;
        yPos = rand() % 39 * 20;

        shape.setFillColor(sf::Color::Red);
        shape.setSize(sf::Vector2f(20,20));
        shape.setPosition(xPos, yPos);

    }

    void newApple() {

        // Refer to constructor
        xPos = rand() % 39 * 20;
        yPos = rand() % 39 * 20;
        shape.setPosition(xPos, yPos);
    }

    void render() {

        window.draw(shape);

    }

};

// Simplier creation of snake segments
struct segment {
    sf::RectangleShape shape;
    int xPos;
    int yPos;
};

// Simple play area square
class Screen {
private:
    sf::RectangleShape box;
    int width = 560;
    int height = 400;
    int paddingX = 120;
    int paddingY = 200;
public:
    void init() {
        box.setOutlineThickness(5);
        box.setOutlineColor(sf::Color(250, 150, 100));
        box.setFillColor(sf::Color::Black);
        box.setSize(sf::Vector2f(width, height));
        box.setPosition(paddingX, paddingY);
    }

    void render() {
        window.draw(box);
    }

};

class Snake {

private:
    int speed;
    int res;
    int length;
    int lastDirection;
    std::array<int,2> lastPosition;
    std::vector<segment> body{};
    
    void initSnakeBody() {

        segment head;
        segment body;
        segment tail;

        // Starting Positions
        head.xPos = 100;
        head.yPos = 60;
        body.xPos = 80;
        body.yPos = 60;
        tail.xPos = 60;
        tail.yPos = 60;

        head.shape.setFillColor(sf::Color::Green);
        body.shape.setFillColor(sf::Color::Green);
        tail.shape.setFillColor(sf::Color::Green);

        head.shape.setSize(sf::Vector2f(res, res));
        body.shape.setSize(sf::Vector2f(res, res));
        tail.shape.setSize(sf::Vector2f(res, res));

        head.shape.setPosition(head.xPos, head.yPos);
        body.shape.setPosition(body.xPos, body.yPos);
        tail.shape.setPosition(tail.xPos, tail.yPos);

        this->body.push_back(head);
        this->body.push_back(body);
        this->body.push_back(tail);

    }

    void updateShapePosition(segment& seg) {

        seg.shape.setPosition(seg.xPos, seg.yPos);

    }

public:
    Snake() {
        std::cout << "Snake created" << "\n";
        speed = 20;
        res = 20;
        length = 3;

        // Right to start off
        lastDirection = 2;

        // These are changed every frame so what they are initialized to does not matter
        lastPosition[0] = 0;
        lastPosition[1] = 0;

        // Shape and position set
        initSnakeBody();
        
    }

    segment getHeadPos() {
        return body[0];
    }

    void setLastPostion(int x, int y) {
        lastPosition[0] = x;
        lastPosition[1] = y;
    }

    void render() {

        for (auto item : body) {

            //std::cout << item.xPos << " " << item.yPos << "\n";
            window.draw(item.shape);

        }
    }

    void appleEaten() {

        length++;

        segment newSeg;
        newSeg.shape.setFillColor(sf::Color::Green);
        newSeg.shape.setSize(sf::Vector2f(res, res));
        newSeg.shape.setPosition(0, 0);

        body.push_back(newSeg);
    }

    void updateSnakeTrail() {


        for (int i = 1; i < length; i++) {

            int temp_x = body[i].xPos;
            int temp_y = body[i].yPos;

            body[i].xPos = lastPosition[0];
            body[i].yPos = lastPosition[1];

            lastPosition[0] = temp_x;
            lastPosition[1] = temp_y;

        }

        for (auto& item : body) {

            updateShapePosition(item);

        }

    }

    void updateSnakeBody() {

        setLastPostion(body[0].xPos, body[0].yPos);

        switch (lastDirection)
        {
            // UP
        case 1:
            body[0].yPos -= speed;
            break;

            // RIGHT
        case 2:
            body[0].xPos += speed;
            break;

            // DOWN
        case 3:
            body[0].yPos += speed;
            break;

            // LEFT
        case 4:
            body[0].xPos -= speed;
            break;
        }

        updateSnakeTrail();

    }


    int getLastDirection() {
        return lastDirection;
    }
    void setLastDirection(int num) {
        lastDirection = num;
    }
};

// REPLACE Params with array of sf::RectangleShapes, probably gonna need to loop through
void draw(Snake* snake, Apple* apple, Screen* screen ) {

    window.clear(sf::Color::Black);
    screen->render();
    apple->render();
    snake->updateSnakeBody();
    snake->render();
    window.display();
}

void foundApple(Apple& apple,Snake& snake) {

    if (apple.xPos == snake.getHeadPos().xPos && apple.yPos == snake.getHeadPos().yPos) {
        apple.newApple();
        snake.appleEaten();
    }

}

int main() {

    // Main Snakey
    Snake snake;

    // Super Apple
    Apple apple;

    // Gameplay area
    Screen screen;
    screen.init();

    // Init the window
    window.setFramerateLimit(12);

    // Time for random
    std::srand(time(0));

    // run the program as long as the window is open
    while (window.isOpen())
    {

        draw(&snake, &apple, &screen);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            int last = snake.getLastDirection();

            if (event.key.code == sf::Keyboard::Up) {
                if (last == 3)break;
                snake.setLastDirection(1);
            }
            else if (event.key.code == sf::Keyboard::Down) {
                if (last == 1)break;
                snake.setLastDirection(3);
            }
            else if (event.key.code == sf::Keyboard::Left) {
                if (last == 2)break;
                snake.setLastDirection(4);
            }
            else if (event.key.code == sf::Keyboard::Right) {
                if (last == 4)break;
                snake.setLastDirection(2);
            }


            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        foundApple(apple, snake);
    }

    return 0;
}