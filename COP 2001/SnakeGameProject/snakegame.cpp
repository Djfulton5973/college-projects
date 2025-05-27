/**********************************************************
 * file: snakegame.cpp
 * author: Darren Fulton
 * class: COP 2001 Summer 2022
 * purpose: create a snake game that works properly
 *********************************************************/

#include <iostream>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include <Eagles/AnimatedCircle.h>

// Constants
//---------------------------------------------------------

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int WALL_THICKNESS = 10;

const sf::Color WALL_COLOR = sf::Color::Blue;

const int SPEED = 100;

// Enums
//---------------------------------------------------------

enum Direction { // Direction where the head is going towards
    North,
    East,
    South,
    West

};

int main() {

    // the window itself
    fgcu::AnimatedWindow window(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake Game");
    window.setColor(sf::Color::Black);

    // counter for how many fruits have been eaten
    int snakeLength = 0;

    // the size of the snake
    int snakeSize = 30;

    // the default direction of the head
    Direction snakeDirection = North;

    // configuration of the entire snake
    fgcu::AnimatedRectangle body[50];
    body[snakeLength].setSize(snakeSize, snakeSize);
    body[snakeLength].setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    body[snakeLength].setFillColor(sf::Color::Red);
    window.addShape(&body[snakeLength]);

    // configuration of the fruit
    fgcu::AnimatedCircle snakeFood = fgcu::AnimatedCircle(12);
    snakeFood.setPosition(100, 50);
    snakeFood.setFillColor(sf::Color::White);
    window.addShape(&snakeFood);

    // the top wall
    fgcu::AnimatedRectangle topWall;
    topWall.setSize(WINDOW_WIDTH, WALL_THICKNESS);
    topWall.setFillColor(WALL_COLOR);
    topWall.setPosition(0, 0);
    window.addShape(reinterpret_cast<fgcu::AnimatedShape *>(&topWall));

    // the left wall
    fgcu::AnimatedRectangle leftWall;
    leftWall.setSize(WALL_THICKNESS, WINDOW_HEIGHT);
    leftWall.setFillColor(WALL_COLOR);
    leftWall.setPosition(0, 0);
    window.addShape(reinterpret_cast<fgcu::AnimatedShape *>(&leftWall));

    // the bottom wall
    fgcu::AnimatedRectangle bottomWall;
    bottomWall.setSize(WINDOW_WIDTH, WALL_THICKNESS);
    bottomWall.setFillColor(WALL_COLOR);
    bottomWall.setPosition(0, WINDOW_HEIGHT - WALL_THICKNESS);
    window.addShape(reinterpret_cast<fgcu::AnimatedShape *>(&bottomWall));

    // the right wall
    fgcu::AnimatedRectangle rightWall;
    rightWall.setSize(WALL_THICKNESS, WINDOW_HEIGHT);
    rightWall.setFillColor(WALL_COLOR);
    rightWall.setPosition(WINDOW_WIDTH - WALL_THICKNESS, 0);
    window.addShape(reinterpret_cast<fgcu::AnimatedShape *>(&rightWall));


    // the loop that keeps the window open
    while (window.nextFrame()) {

        // the input of the keys
        sf::Keyboard::Key input = window.getLastKey();

        switch (input) {

            // head of snake goes up
            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                body[0].setHorizontalSpeed(0);
                body[0].setVerticalSpeed(SPEED * -1);
                snakeDirection = North;

                break;

            // head of snake goes right
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                snakeDirection = East;
                body[0].setVerticalSpeed(0);
                body[0].setHorizontalSpeed(SPEED);

                break;

            // head of snake goes down
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                snakeDirection = South;
                body[0].setHorizontalSpeed(0);
                body[0].setVerticalSpeed(SPEED);

                break;

            // head of snake goes left
            case sf::Keyboard::A:
            case sf::Keyboard::Left:
                snakeDirection = West;
                body[0].setVerticalSpeed(0);
                body[0].setHorizontalSpeed(SPEED * -1);

        }

        // switch statement that adjusts the body of the snake
        switch (snakeDirection) {

            case North:

                for (int i = snakeLength + 1; i > 0; i--) {
                    body[i].setHorizontalSpeed(body[i - 1].getHorizontalSpeed());
                    body[i].setVerticalSpeed(body[i - 1].getVerticalSpeed());
                }
                for (int i = snakeLength + 1; i > 0; i--) {
                    body[i].setPosition(body[i - 1].getPosition().x, body[i - 1].getPosition().y + snakeSize);
                }
                break;

            case East:

                for (int i = snakeLength + 1; i > 0; i--) {
                    body[i].setHorizontalSpeed(body[i - 1].getHorizontalSpeed());
                    body[i].setVerticalSpeed(body[i - 1].getVerticalSpeed());
                }
                for (int i = snakeLength + 1; i > 0; i--) {
                    body[i].setPosition(body[i - 1].getPosition().x - snakeSize, body[i - 1].getPosition().y);
                }
                break;

            case South:

                for (int i = snakeLength + 1; i > 0; i--) {
                    body[i].setHorizontalSpeed(body[i - 1].getHorizontalSpeed());
                    body[i].setVerticalSpeed(body[i - 1].getVerticalSpeed());
                }
                for (int i = snakeLength + 1; i > 0; i--) {
                    body[i].setPosition(body[i - 1].getPosition().x, body[i - 1].getPosition().y - snakeSize);
                }
                break;

            case West:

                for (int i = snakeLength + 1; i > 0; i--) {
                    body[i].setHorizontalSpeed(body[i - 1].getHorizontalSpeed());
                    body[i].setVerticalSpeed(body[i - 1].getVerticalSpeed());
                }
                for (int i = snakeLength + 1; i > 0; i--) {
                    body[i].setPosition(body[i - 1].getPosition().x + snakeSize, body[i - 1].getPosition().y);
                }


        }

        // stops the game when touching the top wall
        if (body[0].getGlobalBounds().intersects(topWall.getGlobalBounds())) {

            window.close();
            break;

        // stops the game when touching the bottom wall
        } else if (body[0].getGlobalBounds().intersects(bottomWall.getGlobalBounds())) {

            window.close();
            break;

        // stops the game when touching the left wall
        } else if (body[0].getGlobalBounds().intersects(leftWall.getGlobalBounds())) {

            window.close();
            break;

        // stops the game when touching the right wall
        } else if (body[0].getGlobalBounds().intersects(rightWall.getGlobalBounds())) {

            window.close();
            break;

        // checks if the head of the snake and the fruit overlaps
        } else if (body[0].getGlobalBounds().intersects(snakeFood.getGlobalBounds())) {

            // snake grows after absorbing the fruit and is placed randomly
            snakeFood.setVisible(false);
            int foodPosX = (rand() % WINDOW_WIDTH - 15) + 5;
            int foodPosY = (rand() % WINDOW_HEIGHT - 15) + 5;
            snakeFood.setPosition(foodPosX, foodPosY);
            snakeFood.setVisible(true);

            // the actual growth of the snake's body
            body[snakeLength + 1] = body[snakeLength];
            sf::Vector2f tailPos = body[snakeLength].getPosition();
            tailPos.y += snakeSize;
            body[snakeLength + 1].setPosition(tailPos.x, tailPos.y);
            window.addShape(&body[snakeLength + 1]);
            snakeLength++;

        }

    } //end of window.nextFrame()

    return 0;

} // end of main