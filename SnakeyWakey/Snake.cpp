#include "Snake.h";



void Snake::initSnakeBody(sf::Sprite board, float gameBoardX, float gameBoardY) {

        segment head;
        segment body;
        segment tail;

        // Starting Positions of snake always inside Game Board
        head.xPos = board.getGlobalBounds().left + gameBoardX / 2;
        head.yPos = board.getGlobalBounds().top + gameBoardY / 2;
        body.xPos = board.getGlobalBounds().left + gameBoardX / 2 - 20;
        body.yPos = board.getGlobalBounds().top + gameBoardY / 2;
        tail.xPos = board.getGlobalBounds().left + gameBoardX / 2 - 20 - 20;
        tail.yPos = board.getGlobalBounds().top + gameBoardY / 2;

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


Snake::Snake(sf::Sprite board, float gameBoardX, float gameBoardY) {
        
    
        speed = gameBoardX / 60;
        res = gameBoardX / 60;
        length = 3;

        // Right to start off
        lastDirection = 2;

        // These are changed every frame so what they are initialized to does not matter
        lastPosition[0] = gameBoardX;
        lastPosition[1] = gameBoardY;

        // Shape and position set
        initSnakeBody(board, gameBoardX, gameBoardY);

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

 void Snake::appleEaten(int &points) {

        length++;
        points++;

        segment newSeg;
        newSeg.shape.setFillColor(sf::Color::Green);
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
     if (getHeadPos().xPos > board.getGlobalBounds().left + board.getGlobalBounds().width)
         return true;
     // Collide with left wall
     else if (getHeadPos().xPos < board.getGlobalBounds().left)
         return true;
     // Collide with bottom wall
     else if (getHeadPos().yPos > board.getGlobalBounds().top + board.getGlobalBounds().height - getHeadPos().shape.getSize().y)
         return true;
     // Collide with top wall
     else if (getHeadPos().yPos < board.getGlobalBounds().top)
         return true;

     // No collision with walls
     return false;

 }

 bool Snake::bodyCollision() {

     // Loop through each segment and compare position to head
     for (int i = 1; i < length; i++) {

         if (getHeadPos() == body[i])
             return true;
     }

     return false;
 }

 bool Snake::collisionHandler(sf::Sprite board) {

     // There was a collision
     if (wallCollision(board) || bodyCollision()) {
         return true;
     }

     // No Collisions Occur
     return false;
 }

 void Snake::movementHandler(sf::Event event) {
     int last = getLastDirection();

             if (event.key.code == sf::Keyboard::Up) {
                 if (last == 3) return;
                    setLastDirection(1);
             }
             if (event.key.code == sf::Keyboard::Down) {
                 if (last == 1) return;
                    setLastDirection(3);
             }
             if (event.key.code == sf::Keyboard::Left) {
                 if (last == 2) return;
                    setLastDirection(4);
             }
             if (event.key.code == sf::Keyboard::Right) {
                 if (last == 4) return;
                    setLastDirection(2);
             }


 }

