#include "Snake.h";
#include "Options.h";



void Snake::initSnakeBody(sf::Sprite board, float gameBoardX, float gameBoardY, bool isPlayer1, char &snakeColor) {
        segment head;
        segment body;
        segment tail;

        setSnakeColor(head.shape, snakeColor);
        setSnakeColor(body.shape, snakeColor);
        setSnakeColor(tail.shape ,snakeColor);

        head.shape.setSize(sf::Vector2f(res, res));
        body.shape.setSize(sf::Vector2f(res, res));
        tail.shape.setSize(sf::Vector2f(res, res));

        // Starting Positions of Player 1 Snake

        int MAX_X = int(gameBoardX) / res;
        int MAX_Y = int(gameBoardY) / res;

        std::cout << "Max columns: " << MAX_X << "\n";
        std::cout << "Max rows: " << MAX_Y << "\n";

        if (!isPlayer1) {
            head.xPos = board.getGlobalBounds().left + head.shape.getGlobalBounds().width * int(MAX_X / 2 - 10);
            head.yPos = board.getGlobalBounds().top + head.shape.getGlobalBounds().height * int(MAX_Y / 2 + 1);
            body.xPos = head.xPos - head.shape.getGlobalBounds().width;
            body.yPos = head.yPos;
            tail.xPos = body.xPos - head.shape.getGlobalBounds().width;
            tail.yPos = head.yPos;
        }
        // Starting Positions of Player 1 Snake
        else {
            head.xPos = board.getGlobalBounds().left + head.shape.getGlobalBounds().width * int(MAX_X / 2 + 10);
            head.yPos = board.getGlobalBounds().top + head.shape.getGlobalBounds().height * int(MAX_Y / 2 + 1);
            body.xPos = head.xPos + head.shape.getGlobalBounds().width;
            body.yPos = head.yPos;
            tail.xPos = body.xPos + head.shape.getGlobalBounds().width;
            tail.yPos = head.yPos;
        }

        head.shape.setPosition(head.xPos, head.yPos);
        body.shape.setPosition(body.xPos, body.yPos);
        tail.shape.setPosition(tail.xPos, tail.yPos);

        this->body.push_back(head);
        this->body.push_back(body);
        this->body.push_back(tail);
}


Snake::Snake(sf::Sprite board, float gameBoardX, float gameBoardY, char& snakeColor, bool isSinglePlayer = true) {
        speed = gameBoardX / 60;
        res = gameBoardX / 60;
        points = 0;
        length = 3;

        // Starting direction
        if (!isSinglePlayer)
            lastDirection = 2;
        else
            lastDirection = 4;

        // These are changed every frame so what they are initialized to does not matter
        lastPosition[0] = gameBoardX;
        lastPosition[1] = gameBoardY;

        // Shape and position set
        initSnakeBody(board, gameBoardX, gameBoardY, isSinglePlayer, snakeColor);
}

void Snake::setSnakeColor(sf::RectangleShape &rect, char &snakeColor) {
    switch (snakeColor) {
    case 'W': {
        rect.setFillColor(sf::Color::White);
        break;
    }
    case 'R': {
        rect.setFillColor(sf::Color::Red);
        break;
    }
    case 'G': {
        rect.setFillColor(sf::Color::Green);
        break;
    }
    case 'B': {
        rect.setFillColor(sf::Color::Blue);
        break;
    }
    case 'Y': {
        rect.setFillColor(sf::Color::Yellow);
        break;
    }
    case 'M': {
        rect.setFillColor(sf::Color::Magenta);
    }
    }
    
}


void Snake::setLastPostion(int x, int y) {
        lastPosition[0] = x;
        lastPosition[1] = y;
}

 void Snake::render(sf::RenderWindow& window) {

        for (auto item : body) {

            window.draw(item.shape);

        }
 }

 void Snake::appleEaten(char &snakeColor) {

        length++;
        points++;

        segment newSeg;
        setSnakeColor(newSeg.shape, snakeColor);
        newSeg.shape.setSize(sf::Vector2f(res, res));
        newSeg.shape.setPosition(-res, -res);

        body.push_back(newSeg);
 }

 void Snake::updateSnakeTrail() {


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

 void Snake::updateSnakeBody() {

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

 bool Snake::wallCollision(sf::Sprite board) {

     // Collide with right wall
     if (getHeadPos().xPos > board.getGlobalBounds().left + board.getGlobalBounds().width - res)
         return true;
     // Collide with left wall
     else if (getHeadPos().xPos < board.getGlobalBounds().left)
         return true;
     // Collide with bottom wall
     else if (getHeadPos().yPos > board.getGlobalBounds().top + board.getGlobalBounds().height - getHeadPos().shape.getSize().y)
         return true;
     // Collide with top wall
     else if (getHeadPos().yPos < board.getGlobalBounds().top - res)
         return true;

     // No collision with walls
     return false;

 }

 bool Snake::bodyCollision() {

     // Loop through each segment and compare position to head
     for (int i = 1; i < length; i++) {

         if (getHeadPos() == body[i]) {
             return true;
         }
     }

     return false;
 }

 bool Snake::collisionHandler(sf::Sprite board) {

     // There was a collision
     if (wallCollision(board) || bodyCollision()) {
         gameOver = true;
         return true;
     }

     // No Collisions Occur
     return false;
 }

 void Snake::movementHandler_P1(sf::Event event) {
     int last = getLastDirection();

             if (event.key.code == sf::Keyboard::Up) {
                 // Do not allow down
                 if (last == 3) 
                     return;
                 else
                    setLastDirection(1);
             }
             if (event.key.code == sf::Keyboard::Down) {
                 // Do not allow up
                 if (last == 1) 
                     return;
                 else
                    setLastDirection(3);
             }
             if (event.key.code == sf::Keyboard::Left) {
                 // Do not allow right
                 if (last == 2) 
                     return;
                 else
                    setLastDirection(4);
             }
             if (event.key.code == sf::Keyboard::Right) {
                 // Do not allow left
                 if (last == 4) 
                     return;
                 else
                    setLastDirection(2);
             }
 }

 void Snake::movementHandler_P2(sf::Event event) {
     int last = getLastDirection();

     if (event.key.code == sf::Keyboard::W) {
         if (last == 3) return;
         setLastDirection(1);
     }
     if (event.key.code == sf::Keyboard::S) {
         if (last == 1) return;
         setLastDirection(3);
     }
     if (event.key.code == sf::Keyboard::A) {
         if (last == 2) return;
         setLastDirection(4);
     }
     if (event.key.code == sf::Keyboard::D) {
         if (last == 4) return;
         setLastDirection(2);
     }
 }

 void Snake::setPointsColor(char snakeColor, sf::Text &points) {
     switch (snakeColor) {
     case 'W': points.setFillColor(sf::Color::White); break;
     case 'G': points.setFillColor(sf::Color::Green); break;
     case 'R': points.setFillColor(sf::Color::Red); break;
     case 'Y': points.setFillColor(sf::Color::Yellow); break;
     case 'B': points.setFillColor(sf::Color::Blue); break;
     case 'M': points.setFillColor(sf::Color::Magenta);
     }
 }

 
